import os
import math
import copy
import sys
from collections import *

os.chdir('/Users/Dana/Documents/0502')
f = open('B-small-attempt0.in','r')
fo = open('B.out','w')
T = int(f.readline())
for ite in range(T):
    temp = str.split(f.readline())
    k,L,s = int(temp[0]),int(temp[1]),int(temp[2])
    keyboard = list(f.readline())
    target = list(f.readline())
    del keyboard[len(keyboard)-1]
    if ite!=(T-1):
        del target[len(target)-1]
    #print(k,L,s)
    #print(keyboard)
    #print(target)

    flag = 1
    for i in range(L):
        if not(target[i] in keyboard):
            flag = 0
    if flag == 0:
        res = 0
    else:
        res = 1
        # check if can start in the middle
        cansplit = 0
        for i in range(L-1,0,-1):
            if target[0:(L-i)]==target[i:L]:
                cansplit = i
        #print(cansplit)
        if cansplit == 0:
            maxbana = math.floor(s/L)
        else:
            maxbana = 0
            current = 0
            while (current+L-1)<=(s-1):
                maxbana = maxbana+1
                current = current+cansplit
        #print(maxbana)

        prob = 1
        for i in range(L):
            prob = prob*keyboard.count(target[i])/k
        expected = (s-L+1)*prob
        res = maxbana-expected
    print(res)
    fo.write('Case #')
    fo.write(str(ite+1))
    fo.write(': ')
    fo.write(str(res))
    fo.write('\n')
fo.close()

