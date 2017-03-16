
import sys

f = sys.stdin

T = int(f.readline())

for t in xrange(1, T+1):
	segs = [int(x) for x in f.readline().split()]
	N = segs[0]
	P = segs[1:]
	s = sum(P)
	s2 = s + s
	sc = s2 / float(N)
	ans = []
	toAdd = 0.0
	posi = 0
	for j in xrange(N):
		i = P[j]
		a = (sc - i) / s
		if a > 0:
			ans.append(a)
			posi += 1
		else:
			ans.append(0.0)
			toAdd += a
	toAdd /= float(posi)
	for i in xrange(N):
		if ans[i] > 0:
			ans[i] += toAdd
	print "Case #%d: %s" % (t, " ".join([str(x*100) for x in ans]))