from sets import Set
import collections

f = open(r'e:\downloads\B-large.in', 'r')

#f = open(r'h:\work\python\code_jam\lawn.txt', 'r')


def solve(G, n, m):
    row_h = [0]*n
    col_h = [0]*m

    for r in range(n):
        for c in range(m):
            row_h[r] = max(row_h[r], G[r][c])
            col_h[c] = max(col_h[c], G[r][c])

    for r in range(n):
        for c in range(m):
            if G[r][c] < row_h[r] and G[r][c] < col_h[c]:
                return 'NO'
    return 'YES'

T = int(f.readline())
for t in range(1, T+1):
    n, m = map(int, f.readline().split())

    G = []
    for _ in range(n):
        G.append(map(int, f.readline().split()))

    print "Case #%d: %s" % (t, solve(G, n, m))


