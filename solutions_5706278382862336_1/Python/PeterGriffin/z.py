import sys
sys.stdin = open('A-large.in', 'r')
sys.stdout = open('A.out','w')

for p in range(int(input())):
	P, Q = map(int, input().split('/'))
	from fractions import gcd
	d = gcd(P,Q)
	P //= d
	Q //= d
	if Q not in ([0] + [2**k for k in range(45)]):
		print("Case #%d: %s" % (p+1, 'impossible'))
	else:
		g = 0
		while P < Q:
			Q //= 2
			g += 1
		print("Case #%d: %d" % (p+1, g))
	

	
