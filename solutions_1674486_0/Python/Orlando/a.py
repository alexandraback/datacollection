#!/usr/bin/env python

import collections

t = int(raw_input())

def dfs(r, p2cs, seen):
    if r in seen:
        return True
    seen.add(r)
    cs = p2cs[r]
    for c in cs:
        if dfs(c, p2cs, seen):
            return True
    return False

for tc in xrange(1, t+1):
    n = int(raw_input())
    cs = set()
    c2ps = collections.defaultdict(lambda: [])
    p2cs = collections.defaultdict(lambda: [])
    for i in xrange(1, n+1):
        cs.add(i)
        c = map(int, raw_input().split())
        for p in c[1:]:
            cs.add(p)
            c2ps[i].append(p)
            p2cs[p].append(i)
    roots = (c for c in cs if c not in c2ps)
    flag = False
    for r in roots:
        if dfs(r, p2cs, set()):
            flag = True
            break
    print "Case #%d: %s" % (tc, "Yes" if flag else "No")
