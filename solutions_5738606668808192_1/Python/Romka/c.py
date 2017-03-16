from random import choice
import sys


def check(s):
    res = []
    for base in xrange(2, 11):
        x = int(s, base)
        j = 2
        while j * j <= x and j < 333:
            if x % j == 0:
                res.append(j)
                break
            j += 1
        if len(res) + 1 != base:
            return []
    return res


N = 32
C = 500
K = 20
cnt = 0
print "Case #1:"
for i in xrange(2 ** K):
    s = "1"
    for j in xrange(N - 2 - K):
        s += choice("01")
    for j in xrange(K):
        s += str((i >> j) & 1)
    s += "1"

    a = check(s)
    if a:
        print s, " ".join(map(str, a))
        cnt += 1
        print >>sys.stderr, cnt
        if cnt == C:
            break
