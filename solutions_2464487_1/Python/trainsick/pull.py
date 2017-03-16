#!/usr/bin/python

def mysqrt(v):
    if v<=1: return v
    g=int(v ** 0.5)
    g2=(g+v//g)//2
    while not (0<=g-g2<=10):
        g=g2
        g2=(g+v//g)//2
    while (g2+1)**2<=v: g2+=1
    return g2

def bullseye():
    z=raw_input().split()
    r=int(z[0])
    t=int(z[1])
    return (-(2*r-1)+mysqrt((2*r-1)**2+8*t))//4

def main():
    t=int(raw_input())
    for i in range(1,t+1):
        print "Case #%d: %d" % (i,bullseye())


main()