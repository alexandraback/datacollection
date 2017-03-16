#!/usr/bin/python

import sys

def bitsum(s,b):
    t=0
    for i in range(len(s)):
        if (1<<i) & b: t+=s[i]
    return t

def uniq(s,b):
    t=[]
    for i in range(len(s)):
        if (1<<i) & b: t.append(s[i])
    t.sort()
    return t

def arri2s(s):
    t=[str(i) for i in s]
    return " ".join(t)

def subset():
    s=[int(i) for i in sys.stdin.readline().split()]
    s=s[1:]
    #print "s=",s
    n=len(s)
    a={}
    for b in range(1,1<<n):
        bs=bitsum(s,b)
        if bs in a and uniq(s,b)!=uniq(s,a[bs]):
            #print uniq(s,b)
            #print uniq(s,a[bs])
            print arri2s(uniq(s,b))
            print arri2s(uniq(s,a[bs]))
            return
        a[bs]=b
    

def mysum():
    tc=int(sys.stdin.readline())
    for i in range(tc):
        print ("Case #%d: " % (i+1))
        subset()
        

mysum()
