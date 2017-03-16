#! /usr/bin/env python

from sys import stdin

ntest = input()

for test in range(ntest):
    a, b = [int(i) for i in stdin.readline().strip().split()]
    p = [float(i) for i in stdin.readline().strip().split()]
    e = b + 1
    prob = 1
    for i in range(a):
        prob *= p[i]
        e = min(b-i+(1-prob)*(b+1), 1+e, b+2)
    print "Case #%d: %f" % (test+1, e)