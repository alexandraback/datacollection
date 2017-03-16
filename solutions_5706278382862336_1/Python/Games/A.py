################################################################
from fractions import Fraction as F


def solve():
    powers = [2 ** i for i in range(41)]
    P, Q = [int(x) for x in input.readline().split('/')]
    print P, Q, F(P, Q),
    f = F(P, Q)
    if f.denominator not in powers:
        return "impossible"
    for i in range(len(powers)):
        if F(P, Q) >= F(1, powers[i]):
            return i
################################################################

from datetime import datetime
time_start = datetime.today()


def now():
    return datetime.today() - time_start

import sys
infilename = sys.argv[1]
outfilename = infilename.replace('.in', '.out')

input = open(sys.argv[1], 'r')
output = open(sys.argv[1].replace('.in', '.out'), 'w')
n = int(input.readline())

for i in range(1, n+1):
    result = solve()
    print "Case #%d: %s \t %s" % (i, result, now())
    output.write("Case #%d: %s\n" % (i, result))
    output.flush()
