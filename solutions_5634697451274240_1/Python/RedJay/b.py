#!/usr/bin/python3

import sys

def getNum():
    return int(sys.stdin.readline())

def getStack():
    s = sys.stdin.readline()
    return list(map(lambda x: 0 if (x == '-') else 1, str(s)))

def flipVal(x):
    if x == 0:
        return 1
    else:
        return 0

def countStack(s):
    if len(s) == 0:
        return 0
    elif len(s) == 1:
        return flipVal(s[0])
    else:
        start = s[0]
        for i in range(1,len(s)):
            if s[i] != start:
                return 1 + countStack(s[i:])
        return flipVal(start)

t=getNum()
for i in range(1,t+1):
    s = getStack()
    print("Case #" + str(i) + ": " + str(countStack(s)))
