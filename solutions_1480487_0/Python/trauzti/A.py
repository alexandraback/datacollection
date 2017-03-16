#! -*- coding: utf-8 -*-
import sys

for i in xrange(1, 1 + int(sys.stdin.readline())):
    l = map(int, sys.stdin.readline().split())
    N = l[0]
    scores = l[1:]
    scores.sort()
    X = sum(scores) + 0.0
    mi = scores[0]
    howmany = scores.count(mi)
    answer = ""
    nextmin = mi
    for item in scores:
        if item > mi:
            nextmin = item
            break
    for j in range(1, N+1):
        tmp = (100 * (2-N*l[j]/X) / (0.0 + N))
        if tmp < 0:
            tmp = 0.0
        answer += " %f" % (tmp)
    print "Case #%d:%s" % (i, answer)
