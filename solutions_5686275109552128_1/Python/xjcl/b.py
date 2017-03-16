from time import clock
from sys import argv

from math import ceil, floor, log
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
ok, so obviously we only want to interrupt if we gain more minutes
    (through better partitioned pancakes) than we lose
    (though ALL OTHER PEOPLE not eating)

for an uneven number 2n+1 it is more ideal to
    partition (n,n+1) first and then eat (n-1,n)  compared to
    eating first (2n) and then partition (n,n)

since gcj loves dynamic programming: one should compute the case of
    <<no interrupts>> first and then add one in an 'optimal' position
    and see if that improves the result
what's the optimal position? naively, I'd say it's interrupting at
    minute 1 and moving half of the biggest pile to an empty one
ok there's my algorithm let's do this :D

ok my algorithm got a bit messier than I hoped but does the job
    and does it in one loop (i.e. few enough cycles to be fast,
    even though it does a lot of BS per cycle, like horribly slow
    list concatenation)
I also made a mistake in my thinking earlier: one has to look
    at all possible number of pancake additions, not just at
    current+1. consider [8,8] for example. [8,4,4] is not better
    but [4,4,4,4] (4+2=6 min) is

incorrect? I already did ten cases by hand and all seems right
    I must've missed an edge case I think

ooohh I haven't considered lifting the pancakes onto a non-empty plate
    but that can't be more optimal can it?
    I can't come up with a scenario where it is

ok came up with the solution after FOREVER and brute-forcing it
    9 is in an optimal case not 9 -> 1+ 5,4 -> 2+ 4,3,2 -> 6
    but 9 -> 1+ 6,3 -> 2+ 3,3,3 -> 5!

the max n for which 2 <= log(pancakes,n) holds is the no of div we want
    n=3: 9 -> 3 3 3 -> 3+2=5
         12 -> 4 4 4 -> 4+2=6
         13 -> 5 4 4 -> 5+2=7
    n=4: 16 -> 4 4 4 4 -> 4+3=7
except sometimes it's better to divide it evenly...
    9,5,5 -> 1+ 5,5,5,4 -> 6
    9,5,5 -> 2+ 5,5,3,3,3 -> 7

---

ok I had a stroke of inspiration and something that might work
    what if we carried a value to undercut (and the start the eating)
    and decreased that by one every time?
    so for 9 6 3 we would so
        9: 9 6 3 -> 9
        8: 9 6 3 -> 1+ 5 4 6 3 -> 7
        7: see 8
        6: see 7
        5: 9 6 3 -> 2+ 5 4 3 3 3 -> 7
        4: 9 6 3 -> 3+ 3 3 3 3 3 3 -> 6
        3: see 4
        2: ...
        1: case we can ignore
only downside is it does get hairy for n=2,3,4
oh maybe we don't need n=2. consider 4 -> 1+ 2 2 -> 3
    it can readily be achieved with n=3
    however we certainly cannot throw out n=3

ok NICE I actually solved this newbie-someone-did-it-in-brainfuck
    problem. it's so incredibly hard to change your outlook on a
    problem after it solidified in your mind.
I wish there was a way to force out-of-box thinking. I was walking
    around and have already given up on this problem (->less stress)
    so that might be a good start
anyway, here's hoping I made no blunders. see myself on the other side!

ok that actually took quite some time (23s) but the .out seems fine :)
"""

def run(data):
    print("in("+str(data)+")")

    min = 1000
    # ops ^= operations ^= special minutes
    # optimal: we do all of these at the start
    md = max(data)
    if md == 1 or md == 2:
        return str(md)

    # we do have to include n=2 bc of 4 -> 2 2 (where upbound=3)
    for upbound in range(md,1,-1):
        ops = 0
        for n in data:
            plates = 1
            while ceil(n/plates) > upbound:
                plates += 1
            # one transport per plate minus initial plate
            ops += (plates - 1)

        candidate = ops + upbound
        if candidate < min:
            min = candidate


    print("ret("+str(min)+")")
    return str(min)

#---------------------------------------------

def read_case(f):
    next(f)
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
