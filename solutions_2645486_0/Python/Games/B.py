################################################################
def solve():
    E,R,N = [int(x) for x in input.readline().split(' ')]
    v = [int(x) for x in input.readline().split(' ')]
    problems = [(E,0,v)]
    total = 0
    while problems:
        # Start with E;
        # End with at least 0
        (S,T,v) = problems.pop()
        if len(v) == 0:
            continue
        m = max(v)
        i = v.index(m)
        before, cur, after = v[:i], v[i], v[i+1:]
        available = min(E, S+R*len(before))
        energy = min(available, available + R*len(after) + R - T)
        print "***", before, cur, after
        print [available, energy, available + R*len(after) + R - T], [S, T, v]
        total += cur*energy
        problems.append((S, energy, before))
        problems.append((min(E, available - energy + R), T, after))
    return total
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
