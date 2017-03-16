

def Check(x, r, t):
	left = x
	right = 2 * x + 2 * r - 1
	return left * right <= t;

def Solve(Case):
	r, t = map(int, input().split())
#	print("r = {0}, t = {1}".format(r, t))
	
	left, right = 0, 1000000000
	while (left + 1 != right):
		mid = (left + right) // 2
#		print("mid = {0}".format(mid))
		if (Check(mid, r, t)):
			left = mid;
		else:
			right = mid;
	print("Case #{0}: {1}".format(Case, left))

T = int(input())
for i in range(1, T + 1):
	Solve(i)
