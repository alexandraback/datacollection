#! /usr/bin/env python

from sys import stdin

ntest = input()

for test in range(ntest):
    n = input()
    minstar = []
    for i in range(n):
        a, b = [int(i) for i in stdin.readline().strip().split()]
        minstar.append([a, b, 0])
    steps = 0
    stars = 0
    minstar.sort(cmp=lambda a,b: b[1] - a[1])
    while stars < 2*n:
        done = False
        for i in minstar:
            if i[2] < 2:
                if i[1] <= stars:
                    done = True
                    stars += 2-i[2]
                    steps += 1
                    i[2] = 2
                    break
        if not done:
            for i in minstar:
                if i[2] < 1:
                    if i[0] <= stars:
                        done = True
                        stars += 1
                        steps += 1
                        i[2] = 1
                        break
        if not done:
            steps = -1 
            break
    print "Case #%d: %d" % (test+1, steps) if steps >= 0 else "Case #%d: Too Bad" % (test+1)