from collections import defaultdict

for t in xrange(1, int(raw_input()) + 1):
	print 'Case #%s:' % t,
	words = [raw_input().split() for _ in xrange(int(raw_input()))]
	wc1 = defaultdict(int)
	wc2 = defaultdict(int)

	for w1, w2 in words:
		wc1[w1] += 1
		wc2[w2] += 1

	out = 0
	for w1, w2 in words:
		if wc1[w1] > 1 and wc2[w2] > 1:
			out += 1
			wc1[w1] -= 1
			wc2[w2] -= 1

	print out
