import sys
t = input()
p = [(0, 0), (1, 0), (0, 1), (1, 1), (0, 2), (1, 2), (2, 0), (2, 1)]
for tt in range(t):
	print >>sys.stderr, tt
	print "Case #%d:"%(tt + 1),
	n = input()
	a = map(float, raw_input().split())
	b = map(float, raw_input().split())
	a = sorted(a)
	b = sorted(b)
	for i in range(n, -1, -1):
		for j in range(i):
			if a[n - i + j] < b[j]:
				break
		else:
			print i,
			break
	a = a[::-1]
	b = b[::-1]
	s = 0
	z = 0
	for i in range(n):
		if a[i] > b[s]:
			z += 1
		else:
			s += 1
	print z
