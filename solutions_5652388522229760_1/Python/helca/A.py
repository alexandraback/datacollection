def solve(n):
	if n == 0:
		return 'INSOMNIA'
	d = {}
	z = 0
	while len(d) < 10:
		z += n
		for c in str(z):
			d[c] = 1
	return z 

t = int(raw_input())
for i in xrange(1, t + 1):
  n = int(raw_input())
  print "Case #{}: {}".format(i, solve(n))