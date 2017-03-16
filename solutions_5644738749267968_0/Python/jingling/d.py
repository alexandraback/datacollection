#!/usr/bin/env python
# -*- coding: utf-8 -*-
import re
import sys
import os
import time
import itertools
import collections

def f(a, b):
    b = set(b[:])
    a = a[:]
    a.reverse()

    z=0

    for x in a:
        mm = max(b)
        if mm > x:
            b.remove(mm)
            z+=1
        else:
            b.remove(min(b))
    return len(a) - z

def g(a, b):
    x = 0
    i,j,n,m = 0,0,len(a), len(b)

    c = 0
    while i<n and j<m:
        if a[i] < b[j]:
            i += 1
            if c > 0:
                x += 1
                c -= 1
        else:
            j+=1
            c+=1

    x += n - i

    return x

def main():
    n = int(raw_input())
    for nn in range(n):
        m = int(raw_input())
        a = sorted(map(float, raw_input().split()))
        b = sorted(map(float, raw_input().split()))
        ans = 0
        #print a
        #print b

        x = f(a, b)

        y = g(a, b)

        print "Case #%d: %s %s" % (nn+1, y, x)



if __name__ == '__main__':
    main()
