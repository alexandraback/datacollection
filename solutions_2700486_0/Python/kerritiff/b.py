from decimal import Decimal
import sys

def isblock(x, y, v):
    if y == 0:
        return True
    if (x-1, y-1) in v and (x+1, y-1) in v:
        return True
    return False

def dfs(c, n, x, y, v, h):
    #print '-- c=', c, 'n=', n
    v = set(v)
    global s, a
    if c == n:
        s += 1
        #print '##', v
        if (x, y) in v:
            a += 1
        return
    if isblock(0, h, v):
        v.add((0, h))
        h += 2
        dfs(c+1, n, x, y, v, h)
        return

    if (-1, h-1) in v:
        nx, ny = 1, h-1
        while not isblock(nx, ny, v):
            nx += 1
            ny -= 1
        v.add((nx, ny))
        dfs(c+1, n, x, y, v, h)
        return
    if (1, h-1) in v:
        nx, ny = -1, h-1
        while not isblock(nx, ny, v):
            nx -= 1
            ny -= 1
        v.add((nx, ny))
        dfs(c+1, n, x, y, v, h)
        return

    nx, ny = 1, h-1
    while not isblock(nx, ny, v):
        nx += 1
        ny -= 1
    vv = set(v)
    vv.add((nx, ny))
    dfs(c+1, n, x, y, vv, h)

    nx, ny = -1, h-1
    while not isblock(nx, ny, v):
        nx -= 1
        ny -= 1
    vv = set(v)
    vv.add((nx, ny))
    dfs(c+1, n, x, y, vv, h)

def solve(n, x, y):
    global s, a, h
    s = 0
    a = 0
    h = 0
    v = set()
    dfs(0, n, x, y, v, h)
    return Decimal(a) / Decimal(s)

t = input()
for i in xrange(1, t+1):
    n, x, y = map(int, raw_input().split())
    #print '-- n= ', n
    sys.stderr.write('-- i=%d, n=%d\n' % (i, n))
    ans = solve(n, x, y)
    print 'Case #%d: %.8f' % (i, ans)
