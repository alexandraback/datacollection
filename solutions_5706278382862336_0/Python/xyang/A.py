import os
import math
import copy
import sys
import numpy as np

os.chdir('C:/Python33/20141C')
f = open('A-small-attempt0.in','r')
fo = open('A-small.out','w')
#f = open('A-large.in','r')
#fo = open('A-large.out','w')
T = int(f.readline())
for ite in range(T):
    fo.write('Case #')
    fo.write(str(ite+1))
    fo.write(': ')
    temp = str.split(f.readline(),sep='/')
    a = int(temp[0])
    b = int(temp[1])
    i = 2
    while i<=a:
        while a%i==0 and b%i==0:
            a,b = int(a/i),int(b/i)
        i = i+1
    #print(a,b)
    if a==b:
        res = 0
    elif a==0 or (b!=int(2**int(math.log2(b)))):
        res = 'impossible'
    else:
        k = 0
        while a>=2**k:
            k = k+1
        a = 2**k
        res = int(math.log2(b))-int(k)+1
    print(res)
    #print(a)
    #print(ite)
    fo.write(str(res))
    fo.write('\n')
fo.close()

