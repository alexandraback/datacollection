from time import clock
from sys import argv
from copy import deepcopy
#import math
#import itertools
#import numpy

def read(f):
    return next(f).strip("\n")
    
def read_singles(f):
    # returns chars of a word
    # or digits of an int
    return list(read(f))
    
def read_int(f, b=10):
    return int(read(f), b)
 
def read_float(f):
    return float(read(f))
 
def read_digits(f, b=10):
    return [int(n, b) for n in read_singles(f)]

#---------------------------------------------

def read_strs(f, s=" "):
    return read(f).split(s)
    
def read_ints(f, b=10, s=" "):
    return [int(n, b) for n in read_strs(f, s)]

def read_floats(f, s=" "):
    return [float(n) for n in read_strs(f, s)]
               
#---------------------------------------------

def read_lines(f, n, reader=read_ints, *args, **kwargs):
    ret = []
    for i in range(n):
        ret.append(reader(f, *args, **kwargs))
    return ret

#---------------------------------------------

class Attack(object):
    def __init__(self, t, wm, em, h):
        self.t = t
        self.wm = wm
        self.em = em
        self.h = h

def iss(a):
    # insertion sorts a list of objects by self.t
    # losely based on http://en.wikipedia.org/wiki/Insertion_sort
    for i in range(1, len(a)):
        to_ins = a[i]
        hole_pos = i
        while hole_pos > 0 and to_ins.t < a[hole_pos-1].t:
            a[hole_pos] = a[hole_pos-1]
            hole_pos -= 1
        a[hole_pos] = to_ins
    # is probably in-place
    #return a

def build_in_head(at, lw):
    for k in range(at.wm, at.em):
        try:
            if at.h > lw[k]:
                lw[k] = at.h
        except:
            lw[k] = at.h
    return lw

def tack(at, wall, lw):
    global sses
    if 1:
        if 1:
            for j in range(at.wm, at.em):
                if j in wall:
                    if at.h > wall[j]:
                        sses += 1
                        lw = build_in_head(at, lw)
                        break
                else:
                    sses += 1
                    lw = build_in_head(at, lw)
                    break
    return lw
        
def run(data):
    attacks = []
    for mongol in data: # shut up I want to call them mongols
        t0, n, wm, em, h, dt, dd, dh = mongol
        for i in range(n):
            attacks.append( Attack(t0+i*dt, wm+dd*i, em+dd*i, h+dh*i) )
    iss(attacks)
    lw = {}
    wall = {}
    today = -1
    global sses
    sses = 0
    for at in attacks:
        if at.t > today:
            # repair wall # wall = lw
            wall = deepcopy(lw)
            # change today
            today = at.t
            print "New day:", today
            print wall
            # then proceed
            lw = tack(at, wall, lw)
            print sses
            print
        else:
            # destroy wall
            print "Still", today
            lw = tack(at, wall, lw)
            print sses
    return sses

#---------------------------------------------

def read_case(f):
    n = read_int(f)
    return read_lines(f, n)

def write_case(f, i, sol):
    f.writelines("Case #%d: %s\n" % (i+1, sol))

#---------------------------------------------

def main():
    f = open(argv[1])
    f2 = open(argv[2], "wt")
    for i in range(read_int(f)):
        print("Init case "+str(i+1)+".")
        write_case(f2, i, run(read_case(f)))
        print("Finished in "+str(clock())+".")
    f.close()
    f2.close()

if __name__ == "__main__":
    main()
