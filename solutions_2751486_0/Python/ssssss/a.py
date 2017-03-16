#!/usr/bin/python3

import math
import sys

def consonant(c):
    if c in ['a','i','o','e','u']: return False
    return True;

def case():
    name, n = sys.stdin.readline().split()
    n = int(n)
    c = 0
    m = 0
    lastleft = 0
    for i in range(0,len(name)):
        if consonant(name[i]): c+=1
        else: c = 0
        if c >= n:
            left = i - n + 1 - lastleft + 1
            right = len(name) - i
            #m = max(m, left*right)
            m+= left*right
            lastleft = i-n+2
            #print(i,lastleft,left)
    return m
    

T = int(sys.stdin.readline())
for i in range(1,T+1):
    print("Case #%s: %s" % (i, case()))
    

