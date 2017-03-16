# coding: utf-8

import math

def solve(R, T):
    hi, lo = 10 ** 18 + 1, 0
    for i in xrange(200):
        mid = (hi + lo) / 2
        ink = (mid / 2) * (2 * R + 1) + 4 * (mid / 2) * (mid / 2 - 1) / 2
        if ink <= T:
            lo = mid
        else:
            hi = mid            
    return (hi if lo % 2 == 0 else lo) / 2

def main():
    TC = int(raw_input())
    for tc in xrange(1, TC + 1):
        R, T = map(int, raw_input().split())
        res = solve(R, T)        
        print 'Case #%d: %d' % (tc, res)

if __name__ == '__main__':
    main()
