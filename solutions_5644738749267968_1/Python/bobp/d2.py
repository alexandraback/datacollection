#!/usr/bin/python
import sys
import math

def war(n,naomi,ken):
    kenptr=0
    for block in naomi:
        while((kenptr<n) and (ken[kenptr]<block)):
            kenptr+=1
        if(kenptr<n):
            del ken[kenptr]
        else:
            return n
        n-=1
    return 0
        
[cases]=map(int,sys.stdin.readline().split());
for caseid in range(cases):
    [n]=map(int,sys.stdin.readline().split());
    naomi=map(float,sys.stdin.readline().split());
    ken=map(float,sys.stdin.readline().split());
    naomi.sort()
    ken.sort()
    resulta=n-war(n,list(ken),list(naomi))
    resultb=war(n,list(naomi),list(ken))
    print "Case #"+str(caseid+1)+":",resulta,resultb
