#!/usr/bin/python
# -*- coding: iso-8859-1 -*-

import sys
import math

with open(sys.argv[1], 'r') as f:

    line = f.readline()
    T = int(line)
    for k in range(T):
        line = f.readline()
        E, R, N = [int(val) for val in line.split()]
        line = f.readline()
        Vs = [int(val) for val in line.split()]
        gain = 0
        window = E/R 
        E_max = E
        if E > R:
            window += 1
        for j in range(N):
            i_max = j
            for i in range(window):
                if i+j <N:
                    if Vs[i+j] > Vs[i_max]:
                        i_max = i+j
            if i_max == j:
                gain += Vs[j] * E
                E = min(E_max, R)
            else :
                gain += Vs[j] * R
        print("Case #"+str(k+1)+": "+str(gain))
        
