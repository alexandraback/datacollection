#! /usr/bin/env python

import sys
fin = open(sys.argv[1], "r")
fout = open("p3.out", "w")

T = int(fin.readline())

for i in xrange(T):
    N = int(fin.readline())
    h = []
    for j in xrange(N):
        nh = map(int, fin.readline().split())
        while nh[1]:
            h.append((nh[0], nh[2]))
            nh[1] -= 1
            nh[2] += 1
    ans = 0
    h.sort(key=lambda x: x[1])
    print h
    if len(h) == 2 and h[0][1] != h[1][1]:
        v = 360./h[0][1] - 360./h[1][1]
        t = ((h[1][0] - h[0][0]) % 360)/v
        intersect = h[1][0]/v
        if intersect * 360./h[0][1] <= 360.:
            end = (360. - h[1][0])/360. * h[1][1]
            while t <= end:
                if t > intersect:
                    ans = 1
                t += 360./v
    fout.write("Case #" + str(i+1) + ": " + str(ans) + "\n")
