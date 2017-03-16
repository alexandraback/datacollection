################################################################
def solve():
    A, N = [int(x) for x in input.readline().split(' ')]
    M = [int(x) for x in input.readline().split(' ')]
    M.sort()
    M.reverse()
    min_so_far = 100000000
    added = 0
    while (M):
        nxt = M.pop()
        while (A <= nxt):
            min_so_far = min(min_so_far, 1+len(M)+added)
            if A <= 1:
                return min_so_far
            added += 1
            A += A-1
        A += nxt
    return min(min_so_far, added)
################################################################

from datetime import datetime
time_start = datetime.today()
def now(): return datetime.today() - time_start

import sys
infilename = sys.argv[1]
outfilename = infilename.replace('.in','.out')

input = open(sys.argv[1], 'r')
output = open(sys.argv[1].replace('.in','.out'), 'w')
n = int(input.readline())

for i in range(1,n+1):
    result = solve()
    print "Case #%d: %s \t %s" % (i, result, now())
    output.write("Case #%d: %s\n" % (i, result))
    output.flush()
