__author__ = 'amin'

tt = int(raw_input())

for _i in xrange(tt):
    n = int(raw_input())
    spd = list()
    pos = list()
    for j in xrange(n):
        d, h, m = map(int, raw_input().split())
        for i in xrange(h):
            spd.append((m + i) * 360)
            pos.append(d)
    ans = 0
    if len(spd) == 2:
        i, j = 0, 1
        if spd[i] < spd[j]: i, j = j, i
        need = max((360 - pos[i]) * (spd[i] / 360), (360 - pos[j]) * (spd[j] / 360))
        if spd[0] != spd[1]:
            tt = (360 - (pos[i] - pos[j])) * (((spd[i] * spd[j]) / (spd[i] - spd[j])) / 360)
            if need >= tt:
                ans = 1
    print "Case #%d: %d" % (_i + 1, ans)

