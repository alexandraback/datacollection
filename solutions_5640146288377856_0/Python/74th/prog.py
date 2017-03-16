#!/usr/bin/env python3
# coding: UTF-8

import sys,math

DEBUG = True
DEBUG = False

qNum = int(sys.stdin.readline())
def debug(s1,s2):
    if DEBUG :
        print(str(s1) + ":" + str(s2))

def ans(q):
    a = 0

    l = sys.stdin.readline().strip().split(" ")
    R = int(l[0])
    C = int(l[1])
    W = int(l[2])

    firstHit = math.floor(C / W)
    debug("FH",firstHit)
    if C % W == 0 :
        allHit = W -1
    else:
        allHit = W
    ans = firstHit + allHit


    print("Case #" + str(q) + ": " + str(ans))
    pass

for q in range(qNum):
    ans(q+1)
