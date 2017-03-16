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

    # naive solution
    # because I suck.

def ctv(s, n): # contains three vowels
    vow = "aeiou"
    row = 0
    for c in s:
        if c not in vow:
            row += 1
            if row == n:
                return True
        else:
            row = 0
    return False        

def run(data):
    s, n = data
    ls = len(s)
    ss = 0
    for i in range(n, ls+1):
        for j in range(0, ls-i+1):
            if ctv(s[j:j+i], n):
                ss += 1
    return ss

#---------------------------------------------

def read_case(f):
    s, n = read_strs(f)
    return [s, int(n)]
    return 42

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
