#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
import math


if __name__ == "__main__":

    fin = open("B-small-0.in", "r")
    fout = open("B-small-0.out", "w")
    T = int(fin.readline())

    for k in xrange(0, T):
        X, Y = map(int, fin.readline().split())
        step = ""
        n=0
        m=0
        if X==0:
            n = 0
        else:
            n = int(math.floor(math.sqrt(2*abs(X))))
            if n*(n+1) > 2*abs(X):
                n -= 1
        print "case " + str(k+1)
        print n
        if X>= 0:
            step += 'E'*n
        else:
            step += 'W'*n

        if Y==0:
            m = 0
        else:
            m = 0
            s = 0
            i = n+1
            while s<abs(Y):
                s += i
                i += 1
                m += 1
            m -= 1
        
        print m
        if Y>= 0:
            step += 'N'*m
        else:
            step += 'S'*m

        remain = abs(X) - n*(n+1)/2
        if X>=0:
            step += 'WE'*remain
        else:
            step += 'EW'*remain

        remain = abs(Y) - (2*n+m+1)*m/2
        if Y>=0:
            step += 'SN'*remain
        else:
            step += 'NS'*remain

        fout.write("Case #%i: %s\n" % (k+1, step))
    
    fin.close()
    fout.close()

