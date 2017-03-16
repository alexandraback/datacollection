from time import clock
from sys import argv

from math import ceil, floor
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
"""

def insert(data, new_member):
    for j in range(len(data)):
        if new_member >= data[j]:
            return data[:j] + [new_member] + data[j:]
    return data + [new_member]


def consider(data, t):

    val = data[0] + t  # takes as long as the slowest eater
    top = data[0]

    data = data[1:]

    if top <= 3:
        return top + t

    val2 = 9
    if top == 9:
        val2 = consider( insert(insert(insert(data,3),3),3) , t+2 )

    for d in [ceil(top/2), floor(top/2)]:
        data = insert(data, d)

    if top + t < val:
        val = top + t

    if val2 < val:
        val = val2

    val3 = consider(data, t+1)
    if val3 < val:
        val = val3

    return val



def run(data):
    print("in("+str(data)+")")
    data.sort()
    data.reverse()

    val = consider(data, 0)

    print(data)
    print("ret("+str(val)+")")
    return str(val)

"""
def run(data):
    print("in("+str(data)+")")
    data.sort()
    data.reverse()
    val = data[0]  # takes as long as the slowest eater
    top = val
    t = 0

    # i: number of interruptions
    for i in range(1, (val+1)):

        print(data,t)
        data = data[1:]

        if top <= 3:
            break

        newd, add = partition(data, top)
        t += add

        for d in newd:
            data = insert(data, d)

        top = data[0]

        if top + t < val:
            val = top + t

    print(data)
    print("ret("+str(val)+")")
    return str(val)
"""

"""
def run(data):
    print("in("+str(data)+")")
    data.sort()
    data.reverse()
    val = data[0]  # takes as long as the slowest eater

    # i: number of interruptions
    # maybe val+1 is a bad upper limit for the range; maybe we need higher
    for i in range(1, (val+1)):

        # optimization that can be removed
        if data[0] <= 3:
            break

        # halve the slowest eater and 'insert' them into their new place
        new_slowest2 = floor(data[0]/2)
        new_slowest = ceil(data[0]/2)
        print(data)

        for j in range(1, len(data)):
            if (new_slowest <= data[j-1]) and (new_slowest2 >= data[j]):
                data = data[1:j] + [new_slowest, new_slowest2] + data[j:]
                break
        else:
            data = data[1:] + [new_slowest, new_slowest2]
        #assert(data == list(reversed(sorted(data)))) #where is my bug? :(

        print(data[0] + i, val)
        if data[0] + i < val:
            val = data[0] + i

    print(data)
    print("ret("+str(val)+")")
    return str(val)
"""

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
