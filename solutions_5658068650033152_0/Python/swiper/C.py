def maxV(row, col, n):
    ab = n/2
    if row >= col:
        row, col = col, row
    r = min(row-2, ab/2)
    w = min(col-2, ab-r)
    return min(r*w + n, row*col)

def solve(row, col, cov):
    for n in range(1, (row+col)*2-3):
        if maxV(row, col, n)>=cov:
            return n
    return (row+col)*2-4
from sys import stdin
readline = stdin.readline

C = int(readline())

for c in range(C):
    row, col, cov = map(int, readline().split())
    print "Case #%d: %d" % (c+1, solve(row, col, cov))
