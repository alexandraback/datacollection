def solve():
	n = int(input())
	hikers = []
	for i in range(n):
		d, h, m = (int(x) for x in input().split())
		for j in range(h):
			hikers.append((d, m + j))
	if len(hikers) == 1:
		return 0
	times = [(360 - d) * m for (d, m) in hikers]
	if abs(times[0] - times[1]) < 1e-8:
		return 0
	if times[0] < times[1]:
		if (720 - hikers[0][0]) * hikers[0][1] <= times[1]:
			return 1
		return 0
	if (720 - hikers[1][0]) * hikers[1][1] <= times[0]:
		return 1
	return 0

t = int(input())
for i in range(t):
	print('Case #{}: {}'.format(i + 1, solve()))
