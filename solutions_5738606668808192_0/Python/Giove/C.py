import sys
import random
from itertools import permutations


def solve():
    n, j = [int(x) for x in sys.stdin.readline().split()]
    k = n/2
    for q in xrange(2**(k-1)+1, 2**(k-1)+1+2*j, 2):
        print str(bin(q))[2:]*2,
        for b in xrange(2, 11):
            print b**k + 1,
        print

t = int(sys.stdin.readline())
for i in xrange(t):
    print "Case #%d:" % (i+1)
    solve()

