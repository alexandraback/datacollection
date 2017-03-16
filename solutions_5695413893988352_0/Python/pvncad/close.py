import sys
import math

def solve(a, b):

    if '?' not in a and '?' not in b:
       return (a, b)

    ra, rb = a, b
    if '?' in a:
        diff = -1
        for x in xrange(10):
            aa, bb = solve(a.replace('?',str(x), 1), b)
            if diff < 0 or math.fabs(int(aa) - int(bb)) < diff:
                diff = math.fabs(int(aa) - int(bb))
                ra, rb = aa, bb
    else:
        diff = -1
        for x in xrange(10):
            aa, bb = solve(a, b.replace('?', str(x), 1))
            if diff < 0 or math.fabs(int(aa) - int(bb)) < diff:
                diff = math.fabs(int(aa) - int(bb))
                ra, rb = aa, bb

    return ra, rb

T = int(raw_input())

for tc in xrange(1, T + 1):
    sa, sb = raw_input().strip().split()
    cscore, jscore = solve(sa, sb)
    print "Case #%d: %s %s" % (tc, cscore, jscore)
