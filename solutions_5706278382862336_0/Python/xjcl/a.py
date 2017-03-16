"""Python2- and Python3-compatible. That's all."""
from time import clock
from sys import argv
#import math
#import itertools
#import numpy
from fractions import gcd
from decimal import Decimal

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

def run(data):
    p, q = int(data[0]), int(data[1])
    reduce_by = gcd(p, q)
    p, q = p/reduce_by, q/reduce_by
    
    if q%2!=0:
        return "impossible"
    dec = Decimal(p)/Decimal(q)
    if len(str(dec)) > 15:
        return "impossible"
    count = 0
    while p/q * 2 <= 1:
        p *= 2
        count += 1
    if p/q != 1:
        count += 1
    if count > 40:
        return "impossible"
    return str(count)

#---------------------------------------------

def read_case(f):
    return read(f).split("/")

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
