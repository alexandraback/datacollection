INF = 100000000
M = 1010

t = int(input())

def cnt(d, c):
	ans = 0
	for x in d:
		ans += (x - 1) // c
	return ans

for i in range(1, t + 1):
	ans = INF
	n = int(input())
	d = [int(x) for x in input().split(' ')]
	for c in range(1, M):
		ans = min(ans, c + cnt(d, c))
	print("Case #" + str(i) + ": " + str(ans))

	
