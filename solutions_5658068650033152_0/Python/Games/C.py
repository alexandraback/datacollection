################################################################
def solve():
    N, M, K = [int(x) for x in input.readline().split(' ')]
    if K <= 4:
        return K
    if M > N:
        M, N = N, M
    extras = (M * N) - K
    if extras <= 4:
        return 2 * (M + N - 2) - extras
    for m in range(M+1):
        if m * m - 4 >= K:
            return 4 * (m - 2)
        if m * m - 4 + 1 >= K:
            return 4 * (m - 2) + 1
        if m * (m + 1) - 4 >= K:
            return 4 * (m - 2) + 2
        if m * (m + 1) - 4 + 1 >= K:
            return 4 * (m - 2) + 3
        if m == M:
            for n in range(m, N+1):
                if (m * n - 4) >= K:
                    return 2 * (m - 2 + n - 2)
                if (m * n - 4) + 1 >= K:
                    return 2 * (m - 2 + n - 2) + 1
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
