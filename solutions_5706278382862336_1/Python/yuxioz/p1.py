#!/usr/bin/python
#
# author: tzeng.yuxio@gmail.com
# usage: cat file.input | ./qround-problem-a.py > file.output

import sys
from fractions import gcd

def solve():
    ti = (sys.stdin.readline().split('/'))
    a = int(ti[0])
    b = int(ti[1])
    c = gcd(a, b)
    a = a / c
    b = b / c
    if ((b & (b-1)) != 0):
        return "impossible"
    for i in range(40):
        d = pow(2, (i+1))
        if d > b:
            return "impossible"
        if a >= (b/d):
            return str(i+1)
    return "impossible"


t = int(sys.stdin.readline())
for i in range(t):
    print 'Case #' + repr(i+1) + ': ' + solve()
