################################################################
def solve():
    C, F, X = [float(x) for x in input.readline().split(' ')]
    i = 0
    T = 0
    T_best = 100000000000.0
    while True:
        T_done = T + X / (2 + i * F)
        T = T + C / (2 + i * F)
        if T_done > T_best:
            return T_best
        else:
            T_best = T_done
        i += 1
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
