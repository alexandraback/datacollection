#!/usr/bin/python

# My python is VERY rusty :)

def can(m, r, t):
    p = (r*2+1)*m + (m-1)*4*(m/2);
    if m%2==1: p+=(m-1)*2;
    return p<=t

ncases = int(raw_input())
for c in range(1,ncases+1):
    r,t = raw_input().split()
    r = int(r)
    t = int(t)
    a = 1
    b = 1000000000
    while a<b:
        m = (a+b)//2
        if   can(m, r, t): a = m+1;
        else:              b = m-1;
    a-=3
    if a<1: a=1
    while can(a+1, r, t): a=a+1
    print "Case #"+str(c)+": "+str(a)
