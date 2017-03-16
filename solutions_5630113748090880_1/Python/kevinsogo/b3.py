from collections import *


for cas in xrange(1,1+input()):
    n = input()
    rows = [tuple(map(int, raw_input().strip().split())) for i in xrange(2*n-1)]
    rows.sort()

    answer = []
    for it in xrange(n):
        if len(rows) > 1 and rows[0][0] == rows[1][0]:
            answer.append(sum(rows[0]) + sum(rows[1]) - sum(r[0] for r in rows))
            rows = [r[1:] for r in rows[2:]]
            rows.sort()
        else:
            results = sorted((Counter(r[0] for r in rows) - Counter(rows[0][1:])).elements())
            answer += results
            break

    print "Case #%s: %s" % (cas, ' '.join(map(str, answer)))