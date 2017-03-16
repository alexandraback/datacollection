from collections import Counter

def solve():
	d = int(input())
	p = [int(x) for x in input().split()]
	ans = max(p)
	for i in range(1, ans):
		cur = i
		for x in p:
			cur += (x - 1) // i
		ans = min(ans, cur)
	return ans

n = int(input())
for t in range(n):
	print("Case #{}: {}".format(t + 1, solve()))
