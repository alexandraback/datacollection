n = int(raw_input())

for cas in range(n):
	s,stats = raw_input().split()
	arr = [int(c) for c in stats]
	ans = 0
	tmp = 0
	for i,x in enumerate(arr):
		if i>tmp:
			ans+=1
			tmp+=1
		tmp+=x
	print 'Case #%d: %d' %(cas+1,ans)