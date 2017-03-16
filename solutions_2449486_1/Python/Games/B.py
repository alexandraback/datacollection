################################################################
def solve():
    N,M = [int(x) for x in input.readline().split(' ')]
    S = [[int(x) for x in input.readline().split(' ')] for i in range(N)]
    def round(S, N, M):
        if M == 1 or N == 1:
            return True
        x = min(min(S))
        for i in range(N):
            if all([x == S[i][j] for j in range(M)]):
                return round(S[:i] + S[i+1:], N-1, M)
        for j in range(M):
            if all([x == S[i][j] for i in range(N)]):
                return round([S[i][:j] + S[i][j+1:] for i in range(N)], N, M-1)
        return False
    return round(S, N, M) and "YES" or "NO"
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
