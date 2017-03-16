#!/usr/bin/python3 -SOO
import math,string,itertools,fractions,re,array,bisect
from math import ceil

"""
d = [float('inf') for _ in range(1000001)]
d[1] = 1
for i in range(1,1000000):
    d[i+1] = min(d[i+1], d[i]+1)
    kr = int(str(i)[::-1].lstrip('0'))
    if kr<=10000001: d[kr] = min(d[kr], d[i]+1)
    n = i
    c = 0
    while n>20:
        ns = str(n)
        zl = int(ceil(len(ns)/2))
        _ns = ns[:len(ns)-zl] + '0'*(zl-1) + '1'
        if int(_ns) > n:
            nl = str(int(ns[:len(ns)-zl])-1)
            if len(nl) == len(ns)-zl and nl!='0':
                _ns = nl + '0'*(zl-1) + '1'
            else:
                _ns = '9'*(zl-1) + '0'*(zl-(len(ns)&1)-1) + '1'
        if _ns == _ns[::-1]:
            _ns = '9'*(zl-1) + '0'*(zl-(len(ns)&1)-1) + '1'
        c += n-int(_ns)+1
        n = int(_ns[::-1])
    if d[i] != c+n: print(i)
print('OK')
"""

for cas in range(1,int(input())+1):
    n = int(input())
    c = 0
    while n>20:
        ns = str(n)
        zl = int(ceil(len(ns)/2))
        _ns = ns[:len(ns)-zl] + '0'*(zl-1) + '1'
        if int(_ns) > n:
            nl = str(int(ns[:len(ns)-zl])-1)
            if len(nl) == len(ns)-zl and nl!='0':
                _ns = nl + '0'*(zl-1) + '1'
            else:
                _ns = '9'*(zl-1) + '0'*(zl-(len(ns)&1)-1) + '1'
        if _ns == _ns[::-1]:
            _ns = '9'*(zl-1) + '0'*(zl-(len(ns)&1)-1) + '1'
        c += n-int(_ns)+1
        n = int(_ns[::-1])
        
        #print(n)
    print('Case #%d: %d'%(cas,c+n))
    
