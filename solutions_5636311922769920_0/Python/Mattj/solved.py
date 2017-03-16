from __future__ import print_function
from array import *
import math
import random
debug = False
test = False
testSize = 1000000

def get_first():
    if test==False:
        return int(input())
    return testSize
def get_next(t):
    x=input().split(" ")
    return [int(x[0]),int(x[1]),int(x[2])]


T = get_first()



for t in range(1, T+1):
    print("Case #" + str(t) + ": ",end='')
    k,c,s = get_next(t)

    n = math.pow(k,c)
    imp = False
    if s*min(c,k) < k:
        print("IMPOSSIBLE")
    else:
        done = 0
        while done < k:
            x = done+1
            for i in range(2,c+1):
                x = (x-1) * k + min(i+done,k)
            print(str(x),end=" ")
            done += min(c,k)
    print("",flush=True)
