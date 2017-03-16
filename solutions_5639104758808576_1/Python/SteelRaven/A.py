def solve():
	n, s = input().split()
	now = 0
	ans = 0
	for i, c in enumerate(s):
		c = int(c)
		if not c:
			continue
		if i > now:
			ans += i - now
			now = i
		now += c
	return ans

n = int(input())
for t in range(n):
	print("Case #{}: {}".format(t + 1, solve()))
