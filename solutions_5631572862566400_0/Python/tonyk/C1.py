from sys import stdin
import itertools

def solve(lst, fs, r):
    nxt = fs[lst[-1]]
    if nxt not in lst:
        solve(lst + (nxt,), fs, r)
    else:
        if nxt == lst[0]:
            if len(lst) > r[0]:
                r[0] = len(lst)
        if nxt == lst[-2]:
            if fs[lst[1]] == lst[0] and len(lst) > r[0]:
                r[0] = len(lst)
            for j in xrange(1, len(fs)):
                if j not in lst:
                    solve(lst + (j,), fs, r)

t = int(stdin.readline())
for i in xrange(t):
    n = int(stdin.readline())
    fs = map(int, stdin.readline().split())
    fs = [-1] + fs

    if n == 3:
        print 'Case #%d: 3' % (i+1)
        continue

    r = [0]
    for j in xrange(1, n+1):
        solve((j,), fs, r)

    print 'Case #%d: %d' % ((i+1), r[0])
