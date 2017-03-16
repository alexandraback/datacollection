#!/usr/bin/python

from collections import deque
from collections import defaultdict

def ir():
    return int(raw_input())

def ia():
    line = raw_input()
    line = line.split()
    return map(int, line)
#              O             T                 F              V                I
#      Z              W                U              X                G
d = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
#      0       1      2      3         4       5      6       7        8       9

def emptyp(m):
    return sum(m.values())==0

def take(n, m):
    for c in d[n]:
        m[c] = m[c] - 1

def solve(s):
    m = defaultdict(int)
    for c in s:
        m[c] = m[c] + 1

    digits = [0]*10

    while True:
        if emptyp(m): break
        while m['Z']>0:
            dd=0; take(dd, m); digits[dd] = digits[dd] + 1
        while m['W']>0:
            dd=2; take(dd, m); digits[dd] = digits[dd] + 1
        while m['U']>0:
            dd=4; take(dd, m); digits[dd] = digits[dd] + 1
        while m['X']>0:
            dd=6; take(dd, m); digits[dd] = digits[dd] + 1
        while m['G']>0:
            dd=8; take(dd, m); digits[dd] = digits[dd] + 1

        while m['O']>0:
            dd=1; take(dd, m); digits[dd] = digits[dd] + 1
        while m['T']>0:
            dd=3; take(dd, m); digits[dd] = digits[dd] + 1
        while m['F']>0:
            dd=5; take(dd, m); digits[dd] = digits[dd] + 1
        while m['V']>0:
            dd=7; take(dd, m); digits[dd] = digits[dd] + 1
        while m['I']>0:
            dd=9; take(dd, m); digits[dd] = digits[dd] + 1

    ans = ''
    for i, di in enumerate(digits):
        for j in range(di):
            ans = ans + str(i)
    return ans

T = ir()
for i in range(T):
    s = raw_input()
    ans = solve(s)
    print 'Case #%d: %s' % (i+1, ans)
