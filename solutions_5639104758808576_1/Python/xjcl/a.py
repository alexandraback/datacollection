from time import clock
from sys import argv
#import math
#import itertools
#import numpy

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

"""
obvious: when inviting friends, always pick Si=0

hm. looks like you just have to take the prefixsum (people clapping)
    and subtract from it the index (people we need to have clapping
    at this point)
    (index starting at 1)
if it is always >=0: no one needs to be invited
    if it is <0 sometimes: take their minimum and invite -min friends
this plays well with the guarantee that aud_list[-1] > 0
    and should finish in O(n) time
"""

def run(data):
    aud_cnt, aud_list = data
    print(aud_cnt)
    print(aud_list)

    prefsum = 0
    min = 0
    for (i,a) in enumerate(aud_list):
        prefsum += a
        deficit = prefsum - i - 1  # -1 bc we started indexing at 0 not 1
        if deficit < min:
            min = deficit

    return str(-min)

#---------------------------------------------

def read_case(f):
    aud_cnt, aud_list = read_strs(f)
    return (aud_cnt, [int(a) for a in aud_list])

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
