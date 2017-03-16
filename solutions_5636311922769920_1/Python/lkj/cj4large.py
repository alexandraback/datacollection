def getind(k, c, g):
	if g > k:
		return 1
	if c == 1:
		return g
	return (g-1)*k**(c-1) + getind(k,c-1,g+1)

def solve(k,c,s):
	if k-min(c,k)*s > 0:
		print('IMPOSSIBLE')
		return
	for i in range(s):
		if c*i > k:
			break
		ind = getind(k,c,c*i+1)
		if ind > k**c:
			print("omit:", ind)
			assert(false)
		print(ind, end=' ')
	print()

tc = int(input())
for t in range(1, tc+1):
	k,c,s = [int(x) for x in input().split()]
	print('Case #%i: ' % t, end='')
	solve(k,c,s)
