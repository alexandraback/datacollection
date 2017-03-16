import os
import math
import copy
import sys

os.chdir('C:/Python33/2014')
f = open('B-large.in','r')
fo = open('B-large.out','w')
T = int(f.readline())
for ite in range(T):
    temp = str.split(f.readline())
    C,F,X = float(temp[0]),float(temp[1]),float(temp[2])
    n = 0
    while (C-X)/(2+n*F)+X/(2+(n+1)*F)<0:
        n = n+1
    s = 0
    for i in range(n):
        s = s+C/(2+i*F)
    s = s+X/(2+n*F)
    print(s)
    fo.write('Case #')
    fo.write(str(ite+1))
    fo.write(': ')
    fo.write(str(s))
    fo.write('\n')
fo.close()

