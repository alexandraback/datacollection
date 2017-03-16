

def cal(n, r):
	return 2 * n * n + (2 * r - 1) * n

def run(r, t):
	
	low = 0
	high = 1000000000000
	
	while low + 1 < high:
		mid = (low + high) / 2
		if cal(mid, r) <= t:
			low = mid
		else:
			high = mid
			
	return low

T = int(raw_input())

for step in range(1, T + 1):
	r, t = map(int, raw_input().rstrip().split())
	print "Case #" + str(step) + ": " + str(run(r, t))


