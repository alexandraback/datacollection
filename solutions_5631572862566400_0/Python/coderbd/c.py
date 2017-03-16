#!/usr/bin/python

t = int(raw_input())
for case_no in xrange(1, t+1):
    n = int(raw_input())
    friends = map(lambda s: int(s)-1, raw_input().split())
    m, ans = 2**n, 0
    for bitmask in xrange(m):
        ls = []
        for sid in xrange(n):
            if (bitmask >> sid & 1) == 1:
                ls.append(sid)
        if len(ls) <= 1:
            continue

        sz = len(ls)
        finish = False
        for i in xrange(sz):
            if finish: break
            for j in xrange(i+1, sz):
                if finish: break
                flag = True
                vis = []

                curr, last = ls[i], ls[i]
                vis.append(curr)
                while True:
                    curr = friends[curr]
                    if curr not in ls:
                        flag = False
                        break
                    if curr in vis:
                        if len(vis) == sz:
                            if curr != vis[0] and curr != vis[-2]:
                                flag = False
                        else:
                            if curr != vis[-2]:
                                flag = False
                        break
                    last = curr
                    vis.append(curr)

                if not flag: continue

                curr = ls[j]
                if curr not in vis:
                    vis.append(curr)
                    while True:
                        curr = friends[curr]
                        if curr not in ls:
                            flag = False
                            break
                        if curr in vis:
                            break
                        vis.append(curr)

                    if curr != ls[i] and curr != last:
                        flag = False
                    if not flag: continue

                if len(vis) == sz:
                    ans = max(ans, sz)
                    finish = True

    print 'Case #%d: %s' % (case_no, ans)