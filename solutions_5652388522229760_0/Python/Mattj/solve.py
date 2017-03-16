from __future__ import print_function
from array import *
import math
import random
debug = False
test = False
debugSize = 1000000

def get_first():
    if test==False:
        return int(input())
    return debugSize
def get_next(t):
    if test==False:
        return int(input())
    n = random.randrange(0, 100000)
    print("next problem: "+str(t))
    return t


T = get_first()

def is_finished(ns):
    if debug:
        print(ns)
    return sum(ns) == 10


for t in range(1, T+1):
    print("Case #" + str(t) + ": ",end='')
    ns = [0 for i in range(10)]
    n = get_next(t)
    if n==0:
        print("INSOMNIA")
    else:
        seen = []
        count = 0
        while True:
            count += 1
            x = n * count
            if debug:
                print("count: "+str(count)+", x:"+str(x))
            while x:
                digit = x % 10
                if debug:
                    print("\tdigit: "+str(digit))
                ns[digit] = 1
                x //= 10
            if is_finished(ns):
                break
        print(str(n*count))
