from time import clock
from sys import argv
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

    # strategy: jump up and down until desired y-value is achieved
    # then jump in the opposite direction of the one in which you want to go and return until
    # x, y is matches

def is_pos(n):
    if n > 0: # this is for the case in which y is zero
        return 1
    return 0

def run(data):
    x, y = data
    s = ""
    # calculate hopping n/s:
    hops_ns = abs(y)
    s = "NS" * (hops_ns)
    if is_pos(y):
        s = s[:-1]
    if x == 0:
        return s
        
    # good. now for the tricky part
    #hopped = 2*hops_ns - is_pos(y)
    # next hop has length (hopped+1) # no wait that's completely independent
    # first determine in which direction I want to hop
    hop_east = True
    if x > 0:
        hop_east = False # hop_east describes initial hop, not general direction.
    hops_ew = abs(x)
    if hop_east == True:
        s += "EW"*hops_ew
    else:
        s += "WE"*hops_ew
    return s

#---------------------------------------------

def read_case(f):
    x, y = read_ints(f)
    return [x, y]

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
