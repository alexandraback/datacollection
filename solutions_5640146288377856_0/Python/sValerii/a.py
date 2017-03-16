def solve(n,k):
	ans = n//k
	r =n % k
	if r > 0:
		ans += k
	else:
		ans += k-1
	return ans

t = input()
for i in range(int(t)):
	(n,m,c) = input().split(' ')
	n = int(n)
	m = int(m)
	c = int(c)
	ans = 0
	if c == 1:
		ans = n * m
	else:
		if n > 1:
			ans = (n-1)*(m//c)
		
		ans += solve(m,c)

	print('Case #%s: %s' % (i+1, ans))

		
