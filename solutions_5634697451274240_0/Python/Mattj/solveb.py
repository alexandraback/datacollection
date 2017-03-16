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
    if test==False:
        return input()
    n = random.randrange(0, 100000)
    print("next problem: "+str(t))
    return t


T = get_first()

def is_finished(ps):
    if debug:
        print(ps,flush=True)
    return sum(ps) == len(ps)

def flip(ps):
    j = 1
    # print('flip:'+str(ps))
    while j<len(ps) and ps[j] == ps[j-1]:
        j+=1
    ps2 = ps[:j]
    # print('sub:'+str(ps2))
    ps2.reverse()
    # print('reverse:'+str(ps2))
    for i in range(len(ps2)):
        ps2[i] = 0 if ps2[i]==1 else 1
    # print('invert:'+str(ps))
    ps[:j] = ps2
    # print(ps,flush=True)

for t in range(1, T+1):
    print("Case #" + str(t) + ": ",end='',flush=True)
    s = get_next(t)
    ps = [0 for i in range(len(s))]
    for i in range(len(s)):
        if s[i]=='+':
            ps[i]=1
    count=0
    while is_finished(ps)==False:
        flip(ps)
        count+=1
    print(str(count),flush=True)
