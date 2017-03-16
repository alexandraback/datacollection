
# -*- coding: cp932 -*-

import sys
import math

inputfile = "B-large.in"
f = open(inputfile)
sys.stdout = open(inputfile.replace(".in", ".txt"),'w')
tc_num = int(f.readline().rstrip())

for tc in range(tc_num):
    l = f.readline().split()
    C = float(l[0])
    F = float(l[1])
    X = float(l[2])
    
    if X > C:
        nf = (X * F - C * F - 2 * C ) / (C * F)
        if nf < 0:
            n = 0
        else:
            n = math.ceil(nf)
    else:
        n = 0
    
    t = 0
    if n > 0:
        for i in range(n):
            t += C / (F * i + 2)
            
    t += X / (F * n +  2)

    print("Case #" + str(tc+1) + ": " + '%.7f' %t)

   
