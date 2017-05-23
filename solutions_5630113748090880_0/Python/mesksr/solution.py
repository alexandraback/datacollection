for t in xrange(int(raw_input())):
	n = int(raw_input())
	d = [0]*(2501)
	for i in range(2*n-1):
		l = map(int, raw_input().split())
		for j in l:
			d[j] = (d[j]+1)%2
	ans = "Case #"+str(t+1)+":"
	for i in range(2501):
		if (d[i]==1):
			ans+=(" "+str(i))
	ans += "\n"
	print ans
