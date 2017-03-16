def getind(k, c, i):
	if c == 1:
		return i
	return (i-1)*k**(c-1) + getind(k,c-1,i)

def solve(k,c,s):
	if k != s:
		print('IMPOSSIBLE')
		return
	for i in range(s):
		print(getind(k,c,i+1), end=' ')
	print()

tc = int(input())
for t in range(1, tc+1):
	k,c,s = [int(x) for x in input().split()]
	print('Case #%i: ' % t, end='')
	solve(k,c,s)
