#!/usr/bin/python2.7

import math

f = open('input.txt', 'r')
T = int(f.readline())

for t in range(T):
    n = int(f.readline())
    if n == 1:
        f.readline()
        print "Case #" + str(t + 1) + ": 0"
    elif n == 2:
        (s1, u, m1) = f.readline().rstrip().split(' ')
        (s2, u, m2) = f.readline().rstrip().split(' ')

        s1 = float(s1)
        s2 = float(s2)
        m1 = float(m1)
        m2 = float(m2)

        t11 = (1 - s1 / 360.0) * m1
        t12 = (2 - s1 / 360.0) * m1
        t21 = (1 - s2 / 360.0) * m2
        t22 = (2 - s2 / 360.0) * m2

        print "Case #" + str(t + 1) + ":",
        if t11 > t22 or t21 > t12:
            print 1
        else:
            print 0
    else:
        for i in range(n):
            f.readline()
        print "Case #" + str(t + 1) + ": 0"

