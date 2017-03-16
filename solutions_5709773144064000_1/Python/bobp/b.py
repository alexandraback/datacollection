#!/usr/bin/python
import sys
import math

def solve(c,f,x):
    rate=2.0
    if(x<c):
        return x/rate
    # advance time to next farm
    time=c/rate
    while(1):
        nofarm=time+(x-c)/rate
        farm=time+(x/(rate+f))
        if(nofarm<farm):
            return nofarm
        rate=rate+f
        # advance time to next farm
        time+=c/rate
     
[cases]=map(int,sys.stdin.readline().split());
for caseid in range(cases):
    [c,f,x]=map(float,sys.stdin.readline().split());
    result=solve(c,f,x)
    print "Case #"+str(caseid+1)+":",result
