#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys,math

def isConso(c):
    if c in ('a','e','i','o','u'):
        return False
    return True

def get(N,n):
    ret=0
    A=-1
    a1=-1
    b1=-1
    L=len(N)
    for i in xrange(L):
        if isConso(N[i])==True:
            if b1==-1 or i>=b1+2:
                a1=i
                b1=i
                if b1-a1>=n-1:
                    #print n,a1,b1,(a1-A)*(L-b1)
                    ret+=(b1-n+1-A)*(L-b1)
                    A=b1-n+1
                    a1=b1-n+2
            elif i==b1+1:
                b1=i
                if b1-a1>=n-1:
                    #print n,a1,b1,(a1-A)*(L-b1)
                    ret+=(b1-n+1-A)*(L-b1)
                    A=b1-n+1
                    a1=b1-n+2
    return ret
    

if __name__=="__main__":
    inFile = sys.argv[1]
    inFileObj = file(inFile)
    inLines = [line.strip() for line in inFileObj]
    nbTest = int(inLines[0])
    pos = 1
    for i in xrange(nbTest):
        #print inLines[pos]
        Nn = [x for x in inLines[pos].split()]
        N = Nn[0]
        n = int(Nn[1])
        pos += 1
        s = 'Case #%d: ' % (i+1)
        s += str(get(N,n))
        print s
