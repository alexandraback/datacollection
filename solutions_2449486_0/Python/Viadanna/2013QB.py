#!/usr/bin/python


def check_design(l):
    n, m, mh = len(l), len(l[0]), 0
    for i in xrange(n):
        if max(l[i]) > mh:
            mh = max(l[i])
    height = [[] for i in xrange(mh + 1)]
    for i in xrange(n):
        for j in xrange(m):
            h = l[i][j]
            height[l[i][j]].append((i, j))
    for h in height[:-1]:
        for p in h:
            i, j = p
            cb, ca = l[i][:j], l[i][j+1:]
            if len(cb) == 0 or max(cb) <= l[i][j]:
                if len(ca) == 0 or max(ca) <= l[i][j]:
                    continue
            rb = [l[k][j] for k in range(i)]
            ra = [l[k][j] for k in range(i+1, n)]
            if len(rb) == 0 or max(rb) <= l[i][j]:
                if len(ra) == 0 or max(ra) <= l[i][j]:
                    continue
            return False
    return True

for t in xrange(1, 1 + int(raw_input())):
    n, m = map(int, raw_input().split())
    if check_design([map(int, raw_input().split()) for _ in xrange(n)]):
        print "Case #%d: YES" % t
    else:
        print "Case #%d: NO" % t
