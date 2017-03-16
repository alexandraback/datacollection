#!/usr/bin/env python
#
# Problem: New Lottery Game
# Language: Python
# Author: KirarinSnow
# Usage: python thisfile.py <input.in >output.out


for case in range(int(raw_input())):
    a, b, k = map(int, raw_input().split())
    s = 0
    for i in range(a):
        for j in range(b):
            if i&j < k:
                s += 1
    
    print "Case #%d: %s" % (case+1, s)
