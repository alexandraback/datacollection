#!/usr/bin/python

import sys
import re
import math
import string

f = open(sys.argv[1],'r')

num = int(f.readline())

for z in range(num):
    n,m,k = [int(x) for x in f.readline().split()]
    #print n,m,k
    if n > m:
        n,m = m,n
    if n <= 2 or k <=4:
        print 'Case #{}: {}'.format(z+1, k)
    else:
        st = 100000
        for x in range(1,n-1):
            for y in range(1,m-1):
                b = k
                a = x*y+2*x+2*y
                if k > a:
                    b = k-x*y
                else:
                    b = 2*x+2*y
                if b < st:
                    st = b
                #print x,y,a,b
        print 'Case #{}: {}'.format(z+1, st)

