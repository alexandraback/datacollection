#!/usr/bin/env python2.6

import sys

def read_int():
    return int(sys.stdin.readline())

def read_ints():
    return map(int, sys.stdin.readline().split())

def read_line():
    return sys.stdin.readline().strip()

def solve():
    values = read_ints()
    N = values[0]
    s = values[1:]
    X = float(sum(s))
    n = len(s)
    m = [0.0] * n
    for i in range(len(s)):
        if s[i] >= (2.0*X - s[i]) / (n - 1):
            m[i] = 0.0
        else:
            m[i] = 100 * (2*X - n*s[i]) / (n * X)
    print " ".join([str(a) for a in m])
              
def main():
    T = read_int()
    
    for case in xrange(1, T + 1):
        print 'Case #%d:' % case,
        solve()

if __name__ == '__main__':
    main()
