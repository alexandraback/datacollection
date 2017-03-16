import sys

from collections import defaultdict

T = int(raw_input())

for tc in xrange(1, T + 1):
    line = raw_input().strip()
    cc = defaultdict(lambda : 0)

    for c in line:
        cc[c] += 1

    dc = [0] * 10

    dc[0] = cc['Z']
    dc[2] = cc['W']
    dc[6] = cc['X']
    dc[8] = cc['G']
    dc[4] = cc['U']

    for (d, s) in [ (0, "ZERO"), (2, "TWO"), (4, "FOUR"), (6, "SIX"), (8, "EIGHT")]:
        for x in s:
            cc[x] -= dc[d]

    dc[3] = cc['H']
    dc[5] = cc['F']
    dc[1] = cc['O']
    dc[7] = cc['S']

    for (d, s) in [(3, "THREE"), (5, "FIVE"), (1, "ONE"), (7, "SEVEN")]:
        for x in s:
            cc[x] -= dc[d]

    dc[9] = cc['I']

    ans = ""

    for d in xrange(10):
        if dc[d]:
            ans += ("%d" % d) * dc[d]

    print "Case #%d: %s" % (tc, ans)
