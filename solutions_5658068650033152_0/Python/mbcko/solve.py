#!/usr/bin/env python

import sys
import itertools


def solve():
    N, M, K = tuple(int(one) for one in sys.stdin.readline().split())
    if N == 1 or M == 1:
        return 2
    if N == 2 or M == 2:
        return K
    
    if N == 3 or M == 3:
        if K > 4:
            return {
                5: 4,
                6: 5,
                7: 6,
                8: 6,
                9: 7,
                10: 8,
                11: 8,
                12: 9,
                13: 10,
                14: 10,
                15: 11,
                16: 12,
                17: 13,
                18: 14,
            }[K]
        #endif
        return K
    if N == 4 or M == 4:
        if K > 4:
            return {
                5: 4,
                6: 5,
                7: 6,
                8: 6,
                9: 7,
                10: 7,
                11: 8,
                12: 8,
                13: 9,
                14: 9,
                15: 10,
                16: 10,
                17: 11,
                18: 12,
                19: 13,
                20: 14,
            }[K]
        #endif
        return K
#enddef

def main():
    T = int(sys.stdin.readline())
    for caseNumber in xrange(1, T+1):
        print "Case #%d: %s" % (caseNumber, solve())
    #endfor
#enddef

if __name__ == '__main__':
    main()
#endif


