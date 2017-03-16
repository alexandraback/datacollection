import sys
import random
from itertools import permutations


def discover(l, k, c):
    # l is a list of (at most) c integers from 0 to k-1
    # return value: which element in 0..k^c-1 to try
    res = 0
    for i, x in enumerate(l):
        res += x * k**i
    assert 0 <= res < k**c
    return res


def solve():
    k, c, s = [int(x) for x in sys.stdin.readline().split()]
    if c*s < k:
        print "IMPOSSIBLE"
        return
    
    a = range(k) # values to try
    l = []
    while len(a) > 0:
        l.append(a.pop())
        if len(l) == c or len(a) == 0:
            # discover l
            print discover(l, k, c)+1,
            l = []
    print



if __name__ == '__main__':
    t = int(sys.stdin.readline())
    for i in xrange(t):
        print "Case #%d:" % (i+1),
        solve()

