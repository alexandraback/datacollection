from sys import stdin
readline = stdin.readline

import fractions
import bisect

Pow2 = [2**i for i in xrange(41)]

T = int(readline())
for t in xrange(1, T+1):
	P, Q = map(int, readline().strip().split('/'))
	gcd = fractions.gcd(P, Q)
	P, Q = P/gcd, Q/gcd
	if Q not in Pow2:
		print 'Case #%d: impossible' % (t)
		continue
	P, Q = P*(Pow2[-1]/Q), Pow2[-1]
	ans = 41 - bisect.bisect_right(Pow2, P)
	print 'Case #%d: %d' % (t, ans)
