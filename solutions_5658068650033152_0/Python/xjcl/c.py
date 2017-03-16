"""Python2- and Python3-compatible. That's all."""
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

def run(data):
    n, m, k = data
    if min(n,m) <= 2:
        return k # no enclosings possible -> only stones can count
    if k <= 4:
        return k
    if k >= 4:
        # 4 stones enclose a fifth field
        # and further 2 stones enclose one further field
        # BUT WHAT IF THE DIMENSIONS DON'T MATCH UP
        # this is the minesweepershit all over again
        pass #...
    # ok here is how we do it
    # we start with a 
    # .x.
    # x_x
    # .x.
    # configuration.
    # then we attempt to bump it up/outwards:
    # .xx.
    # x__x
    # x_x.
    # .x..
    # which adds (last_add+1) fields and 3 stones
    # until we hit a wall...
    # .xx.
    # x__x
    # x__x
    # x_x.
    # .x..
    # which adds (last_add) fields and 2 stones
    # after hitting both walls we'll add (last_add-1) fields and 1 stone
    # .xx.
    # x__x
    # x__x
    # x__x
    # .xx.
    # and finally fill the corners with stones
    last_add = 1
    fields = 1
    stones = 4
    total = fields+stones
    curr_width = 3
    curr_height = 3
    while curr_width < min(n,m):
        if 3 < k-total: # if it is more optimal to add a diagonal
                        # rather than individual stones
            last_add += 1
            fields += last_add
            stones += 3
            total = fields+stones
            curr_width += 1
            curr_height += 1
        else:
            break
    while curr_width < max(n,m): # NOTE: curr_width might be width OR height
        if 2 < k-total:
            fields += last_add
            stones += 2
            total = fields+stones
            curr_width += 1
        else:
            break
    while last_add > 0:
        # assert field (width, height) is maxed out
        if 1 < k-total:
            last_add -= 1
            fields += last_add
            stones += 1
            total = fields+stones
        else:
            break
    ret = stones + (k-total) # covers corners and leftovers
    #if ret >= total:
    #    return stones
    return ret

#---------------------------------------------

def read_case(f):
    return read_ints(f)

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
