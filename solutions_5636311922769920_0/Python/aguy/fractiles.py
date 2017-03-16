def f(k, c, tiles):
	ans = 0
	for i in tiles:
		ans += i
		ans *= k
	if len(tiles) == c:
		return ans // k + 1
	return ans * pow(k, c - len(tiles) - 1) + 1

def ans(k,c,s):
	if c * s < k:
		return "IMPOSSIBLE"
	current = []
	ans = []
	for i in range(k):
		current.append(i)
		if len(current) == c:
			ans.append(f(k,c,current))
			current = []
	if len(current):
		ans.append(f(k,c,current))
	return ' '.join(map(str,sorted(ans)))


n = int(input())
for i in range(n):
	x = ans(*map(int,input().split()))
	print("Case #{0}: {1}".format(i+1, x))
