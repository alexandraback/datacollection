#!/usr/bin/python

import sys

f = sys.stdin


T = int(f.readline())


for index in range(1, T+1):
    [C, F, X] = map(float, f.readline().split())
    
    n_opt = int( (F*X - 2*C) / (F*C) )
    
    if n_opt < 0:
        n_opt = 0
    
    time = 0.
    for k in range(0, n_opt):
        time += C / (2 + k*F)
    time += X / (2 + n_opt*F)
    
    print("Case #{}: {:.7f}".format(index, time))