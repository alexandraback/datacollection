__author__ = 'David'

import sys
import math

T = int(sys.stdin.readline())


def non_trivial_factor(a):
    for b in xrange(2, int(math.ceil(math.sqrt(a))) + 1):
        if a % b == 0:
            return b
    return None


for t in xrange(T):
    print "Case #%d:" % (t + 1)
    n, j = [int(x) for x in sys.stdin.readline().split(' ')]
    start = int('1' + ('0' * (n - 2)) + '1', 2)
    end = int('1' * n, 2)

    found = 0
    for x in range(start, end + 1, 2):
        factors = []
        for base in range(2, 11):
            rep = int("{0:b}".format(x), base)
            f = non_trivial_factor(rep)
            if f is not None:
                factors.append(str(f))

        if len(factors) == 9:
            print "{0:b} {1}".format(x, ' '.join(factors))
            found += 1

        if found == j:
            break
