def f(x):
	ans = 0
	for i in range(1,len(x)):
		if x[i] != x[i-1]:
			ans += 1
	if x[-1] == '-': ans += 1
	return ans

n = int(input())
for i in range(n):
	x = f(input())
	print("Case #{0}: {1}".format(i+1, x))