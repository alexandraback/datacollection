for cases in range(1, int(input()) + 1):
	n = int(input())
	d1 = {}
	d2 = {}
	inputs = []
	ans = 0
	for _ in range(n):
	    a, b = input().split()
	    inputs.append((a,b))
	    d1[a] = d1.get(a,0) + 1
	    d2[b] = d2.get(b,0) + 1
	    if(d1[a] > 1 and d2[b] > 1):
	        ans += 1
	print('Case #%d:' % (cases,), ans)
