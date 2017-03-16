def gao():
	d = int(input())
	p = list(map(int, input().split()))
	ans = max(p)
	for i in range(1, ans):
		ans = min(ans, sum(map(lambda x : (x+i-1)//i - 1, p))+i)
	print(ans)


t = int(input())
for cas in range(t):
	print('Case #%d:' % (cas+1), end=' ')
	gao()
