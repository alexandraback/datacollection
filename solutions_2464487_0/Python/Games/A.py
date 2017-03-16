################################################################
def f(r,n):
    return (2*r*n + n*(2*n-1))

def solve():
    r,t = [int(x) for x in input.readline().split(' ')]
    low,high = 1,10**20
    while high > low+1:
        mid = (low + high) // 2
        if f(r,mid) <= t:
            low = mid
        else:
            high = mid
    return low
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
