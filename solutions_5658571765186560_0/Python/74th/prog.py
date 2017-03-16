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
    X = int(l[0])
    l = sorted(l[1:])
    S = int(l[0])
    L = int(l[1])
    debug("X",X)
    debug("S",S)
    debug("L",L)
    if S*L%X != 0:
        print("Case #" + str(q) + ": RICHARD")
        return

    if X == 1:
        print("Case #" + str(q) + ": GABRIEL")
    if X == 2:
        if (S*L)%2 == 0 :
            print("Case #" + str(q) + ": GABRIEL")
        else:
            print("Case #" + str(q) + ": RICHARD")
    if X == 3:
        if L < 3 :
            print("Case #" + str(q) + ": RICHARD")
        if L == 3:
            if S == 1 :
                print("Case #" + str(q) + ": GABRIEL")
            else :
                print("Case #" + str(q) + ": RICHARD")
        if L == 4:
            if S == 3 :
                print("Case #" + str(q) + ": GABRIEL")
            else :
                print("Case #" + str(q) + ": RICHARD")
    if X == 4:
        if L < 4 :
            print("Case #" + str(q) + ": RICHARD")
        if L == 4:
            if S == 1 :
                print("Case #" + str(q) + ": RICHARD")
            else:
                print("Case #" + str(q) + ": GABRIEL")

for q in range(qNum):
    ans(q+1)
