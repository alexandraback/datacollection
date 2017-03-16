#!/usr/bin/python
#
# author: tzeng.yuxio@gmail.com
# usage: cat file.input | ./qround-problem-a.py > file.output

import sys
from fractions import gcd

def solve():
    ti = (sys.stdin.readline().split(' '))
    m = int(ti[0])
    n = int(ti[1])
    k = int(ti[2])
    if n < m: n, m = m, n
    if k <= 4:
        return str(k)
    s = k
    for i in range(m):
        j = i+1
        if j == 1 or j == 2:
            continue
        p = (k+4) / j
        q = (k+4) % j
        if p > n: continue
        if p == n and q != 0: continue
        if q == 0:
            s = min(s, 2*p+2*j-8)
            continue
        pp = n - p
        jj = m - j
        cap = p*j-4
        if pp > 0:
            for ii in range(pp):
                ij = ii / 2 + 1
                if j - ij*2 > 0:
                    cap += (j - ij*2)
                else:
                    break
            for ii in range(jj):
                ij = ii / 2 +1
                if p - ij*2 > 0:
                    cap += (p - ij*2)
                else:
                    break
        if k <= cap:
            s = min(s, 2*p+2*j-8)
    return str(s)


t = int(sys.stdin.readline())
for i in range(t):
    print 'Case #' + repr(i+1) + ': ' + solve()
