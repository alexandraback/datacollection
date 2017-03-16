


def solve(a,n):
	d = [0]*(n+2)
	
	for e in a:
		
		for j in range(n+1,0,-1):
			if d[j]==1 and j+e <= n:
					d[j+e] = 1

		d[e] = 1
	ans = 0
	for i in range(1,n+1):
		#print(i,)
		if d[i] != 1:
			ans += 1
			for j in range(n,0,-1):
				if d[j]==1 and j+i <= n:
					d[j+i] = 1

	return ans

t = input()
for i in range(int(t)):
	(c,d,v) = input().split(' ')
	a = list(map(int, input().split(' ')))
	ans = solve(a,int(v))
	print('Case #%s: %s' % (i+1, ans))




