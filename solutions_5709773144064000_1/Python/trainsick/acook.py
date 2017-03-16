#!/usr/bin/python

def findn(c,f,x):
    n=0
    while (2+(n+1)*f)*(x-c) >= (2+n*f)*x:
        n+=1
    return n

def timen(c,f,x,n):
    t=x/(2.0+n*f)
    for i in range(n):
        t+=c/(2.0+i*f)
    return t


def test1():
    n=findn(500.0,4.0,2000.0)
    print timen(500.0,4.0,2000.0,n)

def cookie():
    l=raw_input().split()
    tc=int(l[0])
    for casenum in range(tc):
        l=raw_input().split()
        c,f,x=float(l[0]),float(l[1]),float(l[2])
        n=findn(c,f,x);
        t=timen(c,f,x,n)
        print "Case #%d: %.7f" % (casenum+1, t)


cookie()
