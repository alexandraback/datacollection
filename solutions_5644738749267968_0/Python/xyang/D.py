import os
import math
import copy
import sys

os.chdir('C:/Python33/2014')
f = open('D-small-attempt2.in','r')
fo = open('D-small.out','w')
T = int(f.readline())
for ite in range(T):
    n = int(f.readline())
    a1 = str.split(f.readline())
    for i in range(len(a1)):
        a1[i] = float(a1[i])
    a2 = str.split(f.readline())
    for i in range(len(a1)):
        a2[i] = float(a2[i])
    a1 = sorted(a1)
    a2 = sorted(a2)
    print(a1)
    print(a2)
    b1,b2 = list(a1),list(a2)
    flag = 1
    for i in range(len(b1)):
        if b1[i]<b2[i]:
            flag = 0
    while (flag == 0) and (len(b1)>0):
        b1 = b1[1:]
        b2 = b2[:len(b2)-1]
        flag1 = 1
        for i in range(len(b1)):
            if b1[i]<b2[i]:
                flag1 = 0
        flag = flag1
    x = len(b1)
    y = 0
    b1,b2 = list(a1),list(a2)
    for i in range(n):
        j = 0
        temp = b2[j]
        while temp<b1[0]:
            j = j+1
            if j == len(b2):
                temp = 10
            else:
                temp = b2[j]
        b1 = b1[1:]
        if j == len(b2):
            b2 = b2[1:]
            y = y+1
        else:
            b2 = b2[:j]+b2[j+1:]
    print(x,y)
    fo.write('Case #')
    fo.write(str(ite+1))
    fo.write(': ')
    fo.write(str(x))
    fo.write(' ')
    fo.write(str(y))
    fo.write('\n')
fo.close()

