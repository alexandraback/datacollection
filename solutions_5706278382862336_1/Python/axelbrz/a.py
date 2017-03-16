def gcd(a, b):
	return a if b == 0 else gcd(b, a % b)

f = open("a.in", "r")
d = f.read()
f.close()

def ispow2(n):
	while n % 2 == 0:
		n /= 2
	return (n == 1)

def solve(pq):
	p, q = int(pq[:pq.find("/")]), int(pq[pq.find("/")+1:])
	
	g = gcd(p, q)
	p /= g
	q /= g
	if not ispow2(q) or p % 2 == 0: n = 0
	else:
		P, Q = p, q
		n = 0
		while q > p and q % 2 == 0:
			q /= 2
			n += 1
	return "impossible" if n == 0 else str(n)


d = d.split("\n")[:-1]
n = int(d[0])
d = d[1:]

f = open("a.out", "w")
for i in xrange(n):
	s = "Case #%d: %s" % (i+1, solve(d[i]))
	print s
	f.write(s+"\n")
f.close()

