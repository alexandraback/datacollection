cases = int(input())

def gcd(a,b):
	if b:
		return gcd(b, a % b)
	else:
		return a

def solve(n, d, i):
	if i == 40:
		return -1
	t = 0
	while n < d:
		n *= 2
		t += 1
	rem = n - d
	if rem:
		res = solve(rem, d, i+1)
		if res == -1: return -1
	return t

for c in range(cases):
	st = list(map(int, input().split('/')))
	n = st[0]
	d = st[1]
	g = gcd(n,d)
	n /= g
	d /= g
	ans = solve(n,d,0)
	if ans != -1:
		print("Case #%d: %d" % (c+1,ans))
	else:
		print("Case #%d: impossible" % (c+1,))
