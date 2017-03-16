#!/usr/bin/python
# -*- coding: iso-8859-1 -*-
import sys
import math

with open(sys.argv[1], 'r') as f:
    for k in range(int(f.readline())):
        N = int(f.readline())
        if N == 0:
            print("Case #"+str(k+1)+": INSOMNIA")
        else:
            present = [False for i in range(10)]
            acc = N
            while True:
                for digit in str(acc):
                    present[int(digit)] = True
                if False not in present:
                    print("Case #"+str(k+1)+": "+str(acc))
                    break
                acc += N
        
