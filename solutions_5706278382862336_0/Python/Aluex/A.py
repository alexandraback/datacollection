import sys, gmpy
s = sys.stdin.read().split('\n')
N = int(s[0])
Prefix = "Case #"
#print s
for x in range(N):
	input = s[x+1]
	t = [int(xls) for xls in input.split('/')]
	p = t[0]
	q = t[1]
	gcd = gmpy.gcd(p,q)
	p /= gcd
	q /= gcd
	if 2**40 % q != 0:
		res = "impossible"
	else:
		num = (p * 2**40) / q
		for test in range(39, -1, -1):
			if num >= 2**test:
				res = str(40 - test)
				break
	print "Case #%d: %s" % (x+1, res)
	