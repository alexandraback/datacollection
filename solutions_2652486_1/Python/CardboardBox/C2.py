t = raw_input()

n_sets, n, m, k = map(int,raw_input().split())

print 'Case #1:'

def gcd(a,b):
	while b!=0:
		a,b = b,a%b
	return a

def lcm(a,b):
	return a*b/gcd(a,b)
	
for i in range(n_sets):
	set = map(int,raw_input().split())
	l = reduce(lcm,set)
	factors = []
	while l > 1 or len(factors) < n:
		for f in range(2,m+1):
			if l % f == 0 or (l == 1 and len(factors) < n):
				factors.append(f)
				l /= f
	while len(factors) > n:
		factors.sort()
		f = factors[0]*factors[1]
		factors = factors[2:]
		factors.append(f)
	print ''.join(map(str,factors))