################################################################
def solve():
    A,B = [int(x) for x in input.readline().split(' ')]
    p = [float(x) for x in input.readline().split(' ')]
    minCost = 2+B
    prod = 1
    for i in range(0,A+1):
        cost = 1 + (B-A) + 2*(A-i) + (1-prod)*(1+B)
        minCost = min(cost, minCost)
        if i < A:
            prod *= p[i]
    return minCost
    # option 1 costs 1 +2d + (B-A) + (1-prod)(1+B)
    # option 2 costs 1 + (B-A) + (1-prod)(1+B)
    # option 3 costs 2 + B
    return (A,B,p)

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
