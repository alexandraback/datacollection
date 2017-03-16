import sys


k = int(sys.stdin.readline())
for id, line in enumerate(sys.stdin):
	line = map(int, line.split())
	n = line[0]
	a = line[1:]
	x = [-1]*10**7
	print 'Case #%d:' % (id+1)
	ok = False

	for i in xrange(1 << 20):
		sm = 0
		for j in xrange(20):
			if i & (1 << j):
				sm += a[j]
		if x[sm] != -1:
			for j in xrange(20):
				if i & (1 << j):
					print a[j],
			print
			for j in xrange(20):
				if x[sm] & (1 << j):
					print a[j],
			ok = True
			print
			break
		x[sm] = i
	if not ok:
		print 'Impossible'

# print ''.join(sorted(d.keys()))
# print ''.join(sorted(d.values()))
# print d