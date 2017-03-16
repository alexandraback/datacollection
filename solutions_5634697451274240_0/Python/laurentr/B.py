#!/usr/bin/python
# -*- coding: iso-8859-1 -*-
import sys

with open(sys.argv[1], 'r') as f:
    for k in range(int(f.readline())):
        stack = f.readline().strip()
        parity = 0
        flips = 0
        while len(stack):
            if parity == 0:
                stack = stack.rstrip('+')
            else:
                stack = stack.rstrip('-')
            if len(stack) == 0:
                break
            if parity == 0:
                stack = stack.rstrip('-')
            else:
                stack = stack.rstrip('+')
            flips += 1
            parity = 1 - parity
        print("Case #"+str(k+1)+": "+str(flips))
        
