#!/usr/bin/python

import sys
import re
import math
import string

f = open(sys.argv[1],'r')

num = int(f.readline())

for z in range(num):
    p,q = [int(x) for x in f.readline().split('/')]
    p2 = 0
    q2 = 0
    while p%2 == 0:
        p /= 2
        p2 += 1
    while q%2 == 0:
        q /= 2
        q2 += 1
    if p%q > 0:
        print 'Case #{}: impossible'.format(z+1)
    else:
        p /= q
        fr = 0
        while 2**(fr+1) <= p:
            fr += 1
        print 'Case #{}: {}'.format(z+1, q2-p2-fr)
