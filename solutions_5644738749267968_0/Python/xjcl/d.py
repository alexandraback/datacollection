"""Python2- and Python3-compatible. That's all."""
from time import clock
from sys import argv
from copy import deepcopy as dc
#import math #import itertools #import numpy

def read(f):
    return next(f).strip("\n")
    
def read_singles(f):
    # returns chars of a word
    # or digits (as strings) of an int
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

def optimal_war(naomi, ken):
    points = 0
    for i in range(len(naomi)):
        """If Naomi plays a tile larger than all of
            Ken's: Ken throws away his smallest one."""
        if naomi[0] > ken[0]:
            points += 1
            naomi.pop(0)
            ken.pop()
        else:
            naomi.pop(0)
            ken.pop(0)
    return points

def optimal_d_war(naomi, ken):
    n = len(naomi)
    points = 0
    for i in range(n-1, -1, -1):
        if naomi[i] > ken[-1]:
            points += 1
            naomi.pop(i)
            ken.pop()
    return points

def run(data):
    naomi, ken = data
    naomi, ken = sorted(naomi), sorted(ken)
    naomi.reverse()
    ken.reverse() # high -> low
    """Deepcopy is needed here else optimal_d_war will alter the list permanently!"""
    return str(optimal_d_war(dc(naomi), dc(ken)))+" "+str(optimal_war(naomi, ken))

#---------------------------------------------

def read_case(f):
    read_int(f)
    return read_lines(f, 2, read_floats)

def write_case(f, i, sol):
    f.writelines("Case #"+str(i+1)+": "+str(sol)+"\n")

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
