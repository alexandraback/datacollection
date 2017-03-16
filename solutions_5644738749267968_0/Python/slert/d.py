def solve():
	n = int(raw_input())
	nao = sorted(map(float, raw_input().split()))
	ken = sorted(map(float, raw_input().split()))

	ndwar = n
	j = 0
	for i in xrange(n):
		if nao[i] < ken[j]:
			ndwar-=1
		else:
			j+=1

	nwar = n
	j = 0
	for i in xrange(n):
		while j<n and nao[i] > ken[j]:
			j+=1
		if j<n:
			j+=1
			nwar-=1
			
	return [ndwar,nwar]
	

tc = int(raw_input())
for ti in xrange(tc):
	[a,b] = solve();
	print "Case #%d: %d %d" % (ti+1,a,b)