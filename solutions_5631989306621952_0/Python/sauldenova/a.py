#!/usr/local/bin/python3

from __future__ import print_function

T = int(input())
for t in range(1, T + 1):
    print("Case #", t, ": ", sep= '', end='')
    line = str(input()).strip()
    finalstr = ""
    for c in line:
        final1 = finalstr + c
        final2 = c + finalstr
        if final1 > final2:
            finalstr = final1
        else:
            finalstr = final2
    print(finalstr)
