import sys

inp = [[int(j) for j in i.split(' ')] for i in sys.stdin.read().strip().splitlines()]
tst = inp[1:]

def f(r0, n):
    return n*((r0+1)**2 - r0**2) + 2*n*(n-1)

for T in xrange(len(tst)):
    r, t = tst[T]
    hyp, hyplen = 2**64, 2**63
    while hyplen > 0:
        if f(r, hyp) > t:
            hyp -= hyplen
        elif f(r, hyp) < t:
            hyp += hyplen
        hyplen /= 2
    hyp = max(0, hyp-100)
    while f(r, hyp+1) <= t:
        hyp += 1
    print 'Case #%d: %d' % (T+1, hyp)
