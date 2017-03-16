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
if x>=7 Richard immediately wins
    (see the 2nd example of the 7-ominoes -> impossible-to-fill hole)
    ###
    # # << no one's getting in there now
    ##
Idea: take the tile you're given and expand it into a rectangular area
    as small as possible. then fill the rest up with #### or so tiles

x=1 and x=2 are equally trivial
x=3: we have tiles
    ## (notation: #/##) and ###
    #
    hm, Richard shouldn't be able to do much by choosing.
    hypothesis: Gabriel's optimal answer to #/## is #/##
        right next to it to make a 2x3
    if I could prove Richard is always better off choosing
        #/## over ### that would help a lot


"""
def run(data):
    x, gr, sm = data

    Win = "GABRIEL"
    Fail = "RICHARD"

    # first if: cell number and area covered by ominoes don't match
    if gr * sm % x:
        return Fail

    if gr < sm:
        gr,sm = sm,gr

    # hole, see above
    if x > 6:
        return Fail

    """
    cases failing for x=2 are caught in first if
    if x == 1 or x == 2:
        return Win
    """

    if x == 3:
        # choose #/## -> spill
        if sm == 1:
            return Fail
        """
        I think I'll just hardcode for the small case
          as I simply can't see the 'catch' in here
          From what I'm seeing atm any field greaterequal 3x4
          for x=4 seems to work out (given first-if)
        sm == 2 and gr in [2,4]  already caught in first if
        4x4 caught in first if
          3x4 can be reduced to 3x3, which can obvs be won
        """

    if x == 4:
        """
        if sm == 1:
            return Fail
        # gr is in [2,4]. always choose #/##/#
        if sm == 2:
            return Fail
        # sm=3 implies gr=4 (first if)
        if sm == 3:
            return Win
        # left: 4x4
        return Win
        """
        if sm == 1 or sm == 2:
            return Fail

    return Win

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
