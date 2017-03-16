def cal(r, n):
	return 2 * r * n + n + n * (n - 1) * 2

def bs(s, t):
	l = 1
	r = 10000000000
	ans = 1
	while l <= r:
		m = (l + r) / 2
		if cal(s, m) <= t:
			ans = m
			l = m + 1
		else:
			r = m - 1
	return ans

cases = input()
print cases
for i in range(1, cases+1):
	(r, t) = map(int, raw_input().split())
	ans = bs(r, t)
	print ans
