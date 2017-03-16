#!/usr/bin/python
# -*- coding: iso-8859-1 -*-
import sys
import math

with open(sys.argv[1], 'r') as f:
    for k in range(int(f.readline())):
        [K, C, S] = [int(i) for i in f.readline().split()]
        if S < K:
            print("Case #"+str(k+1)+": IMPOSSIBLE")
        else:
            power = int(math.pow(K,C-1))
            res = [str(1 + i*power) for i in range(S)]
            print("Case #"+str(k+1)+": "+' '.join(res))
        
