import sys
import random
from itertools import permutations


def solve():
    n = int(sys.stdin.readline())
    if n == 0:
        print "INSOMNIA"
    else:
        digits = set()
        m = 1
        while len(digits) < 10:
            for d in str(m*n):
                digits.add(d)
            m += 1
        print (m-1)*n


t = int(sys.stdin.readline())
for i in xrange(t):
    print "Case #%d:" % (i+1),
    solve()

