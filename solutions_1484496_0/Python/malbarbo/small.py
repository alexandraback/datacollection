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
    S = values[1:]
    sums = {}
    for i in range(0, 1 << 20):
        r = []
        j = 0
        while i > 0:
            if i % 2 == 1:
                r.append(j)
            i /= 2
            j += 1
        sum = 0
        for i in r:
            sum += S[i]
        if sums.has_key(sum):
            print
            print " ".join(str(S[a]) for a in sums[sum])
            print " ".join(str(S[a]) for a in r)
            return
        sums[sum] = r

def main():
    T = read_int()
    
    for case in xrange(1, T + 1):
        print 'Case #%d:' % case,
        solve()

if __name__ == '__main__':
    main()
