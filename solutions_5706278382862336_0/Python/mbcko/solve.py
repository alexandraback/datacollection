#!/usr/bin/env python

import sys
import collections
from fractions import Fraction



def solve():
    P, Q = list(int(one) for one in sys.stdin.readline().strip().split("/"))
    vid = Fraction(P, Q)
    anc = []
    for index in range(1, 41):
        vid *= 2
        if vid == 1:
            return anc[0] if anc else index
        elif vid > 1:
            anc.append(index)
            vid -= 1
    #endfor
    return "impossible"
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


