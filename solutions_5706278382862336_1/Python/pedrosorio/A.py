def gcd(a,b):
	if b == 0:
		return a
	return gcd(b, a%b)


def count_bits(n):
	ct = 0
	while n > 0:
		ct += n%2
		n /= 2
	return ct

def comp_sol(a,b):
	sol = 1
	while 2*a < b:
		b /= 2
		sol += 1
	return sol


T = int(raw_input())
for case in xrange(1, T+1):
	P,Q = map(int,raw_input().split('/'))
	g = gcd(P,Q)
	P /= g
	Q /= g
	if count_bits(Q) > 1:
		sol = "impossible"
	else:
		sol = comp_sol(P,Q)
	print "Case #" + str(case) + ": " + str(sol)