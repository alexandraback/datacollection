import os
import math
import copy
import sys
from collections import *
import itertools

os.chdir('/Users/Dana/Documents/0502')
f = open('C-small-attempt0.in','r')
fo = open('C.out','w')
T = int(f.readline())
for ite in range(T):
    temp = str.split(f.readline())
    c,d,v = int(temp[0]),int(temp[1]),int(temp[2])
    temp = str.split(f.readline())
    exist = [0]*d
    for i in range(d):
        exist[i] = int(temp[i])
    #print(c,d,v)
    #print(exist)
    possible = [0]
    for l in range(1,d+1):
        for x in itertools.permutations(exist,l):
            possible = possible+[sum(x)]
    possible = set(possible)
    possible = list(possible)
    #print(possible)
    res = 0
    for i in range(1,v+1):
        if not (i in possible):
            res = res+1
            for j in range(len(possible)):
                if possible[j]<i and not((i-possible[j]) in exist):
                    add = i-possible[j]
            #print(add)
            exist = exist+[add]
            for j in range(len(possible)):
                possible = possible+[add+possible[j]]
            possible = set(possible)
            possible = list(possible)
            #print(possible)
    print(res)
    fo.write('Case #')
    fo.write(str(ite+1))
    fo.write(': ')
    fo.write(str(res))
    fo.write('\n')
fo.close()

