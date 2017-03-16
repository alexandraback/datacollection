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
        
def d_war(n,naomi,ken):
    if(n==0):
        return 0
    if(naomi[0]>ken[n-1]):
        return n
    sacrafice=d_war(n-1,naomi[1:],ken[0:n-1])
    if(naomi[0]<ken[0]):
        return sacrafice
    attack=1+d_war(n-1,naomi[1:],ken[1:])
    if(attack<sacrafice):
        return sacrafice
    return attack


[cases]=map(int,sys.stdin.readline().split());
for caseid in range(cases):
    [n]=map(int,sys.stdin.readline().split());
    naomi=map(float,sys.stdin.readline().split());
    ken=map(float,sys.stdin.readline().split());
    naomi.sort()
    ken.sort()
    resulta=d_war(n,naomi,ken)
    resultb=war(n,naomi,ken)
    print "Case #"+str(caseid+1)+":",resulta,resultb
