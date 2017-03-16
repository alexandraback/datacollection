T = int(input())
for tc in range(T):
	(C, F, X) = (float(x) for x in input().split())
	res = X
	rate = 2
	cur = 0
	for extra in range(100000):
		res = min(res, cur + X / rate)
		cur += C / rate
		rate += F
	print('Case #{}: {}'.format(tc+1, res))