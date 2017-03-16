#!/usr/bin/env python
f = open('input.txt')
tests = int(f.readline())

def prob_error(p, k):
    # prob for no error.
    if k==0:
        return 1
    return reduce(lambda a,b : a*b, p[:k])

for test in xrange(1, tests+1):
    A, B = map(int, f.readline().split())
    p = map(float, f.readline().split())
    ex = []
    for k in xrange(0, A):
        # exp when deleting k character.
        t = prob_error(p, A-k)
        ex.append(t * (2*k + B - A + 1) + (1-t)*(2*k+2*B-A+2))
    ex.append(2+B)
    print "Case #%d: %r" % (test, min(ex))
