import re

def back(ss):
    global sumt, maxt, cnt
    if len(ss) == s:
        t = 0
        for i in range(s):
            if ss[i:].startswith(ls):
                t += 1
        cnt += 1
        sumt += t
        maxt = max(maxt, t)
        return
    for i in ks:
        back(ss + i)

for tc in range(1, int(raw_input()) + 1):
    k, l, s = tuple([int(i) for i in raw_input().split()])
    ks = raw_input().strip()
    ls = raw_input().strip()
    sumt = maxt = cnt = 0
    back("")
    print "Case #%d: %.7f" % (tc, maxt - float(sumt) / float(cnt))
