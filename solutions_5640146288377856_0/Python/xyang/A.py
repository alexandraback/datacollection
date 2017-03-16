import os
import math
import copy
import sys
from collections import *

os.chdir('/Users/Dana/Documents/0502')
f = open('A-small-attempt1.in','r')
fo = open('A.out','w')
T = int(f.readline())

for ite in range(T):
    temp = str.split(f.readline())
    r,c,w = int(temp[0]),int(temp[1]),int(temp[2])
    #print(r,c,w)
    if r==1:
        if c%w==0:
            res = math.floor(c/w)+w-1
        else:
            res = math.floor(c/w)+w
    print(res)
    fo.write('Case #')
    fo.write(str(ite+1))
    fo.write(': ')
    fo.write(str(res))
    fo.write('\n')
fo.close()

