def is_p(n):
	x = str(n)
	p = len(x)
	for i in xrange(0, p/2):
		if not x[i] == x[p-1-i]:
			return False
	return True

li = []

for i in xrange(1, 100):
	if is_p(i):
		if is_p(i*i):
			li.append(i*i)

a = int(raw_input())

for i in xrange(0,a):
	p = [int(k) for k in raw_input().rstrip().split()]
	count = 0
	for j in li:
		if j >= p[0] and j <= p[1]:
			count = count + 1
	print "Case #%d: %d" % (i+1, count)