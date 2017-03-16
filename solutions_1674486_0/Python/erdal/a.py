import sys


def toadj(m):
    N = len(m)
    r = [[0] * N for n in xrange(N)]
    for i in xrange(N):
        for j in xrange(len(m[i])):
            r[i][m[i][j] - 1] = 1
    return r

def solve(m):
    N = len(m)
    adjm = toadj(m)
    paths = adjm

    for k in xrange(N):
        for i in xrange(N):
            for j in xrange(N):
                paths[i][j] = paths[i][j] + paths[i][k] * paths[k][j]
    for i in xrange(N):
        for j in xrange(N):
            if paths[i][j] > 1:
                return "Yes"
    return "No"


T = int(raw_input())
for t in xrange(T):
    N = int(raw_input())
    m = []
    for n in xrange(N):
        line = sys.stdin.readline().strip().split()
        line = line[1:]
        ms = map(int, line)
        m.append(ms)

    print 'Case #%d: %s' % (t+1, solve(m))
