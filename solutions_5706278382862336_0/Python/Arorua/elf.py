def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a % b)

def run(k):
	p, q = raw_input().split('/')
	p, q = int(p), int(q)
	d = gcd(p, q)
	p, q = p / d, q / d
	ans, r = -1, 2
	for i in range(40):
		if p * r >= q:
			if ans < 0: ans = i + 1
			p = p * r - q
			q = q * r
			if p == 0: break
			d = gcd(p, q)
			p, q = p / d, q / d
		r = r * 2
	if p != 0:
		print 'Case #%d: impossible' % (k, )
	else:
		print 'Case #%d: %d' % (k, ans)

k = input()
for i in range(k):
	run(i+1)
