for t in xrange(1,1+int(raw_input())):
	k,n=map(int,raw_input().split())
	start=[int(x)-1 for x in raw_input().split()]
	chests=[]
	for _ in xrange(n):
		row=[int(x)-1 for x in raw_input().split()]
		chests.append((row[0],row[2:]))
	cache={}
	def dfs(left,have):
		call=left,tuple(have)
		if call not in cache:
			cache[call]=_dfs(left,have)
		return cache[call]
	def _dfs(left,have):
		if not left:
			return()
		i=0
		exp=1
		while exp<=left:
			if left&exp:
				chest=chests[i]
				if have[chest[0]]:
					nhave=have[:]
					nhave[chest[0]]-=1
					for j in chest[1]:
						nhave[j]+=1
					ans=dfs(left&~exp,nhave)
					if ans is not None:
						return(i,)+ans
			i+=1
			exp*=2
	ans=dfs(2**n-1,[start.count(i)for i in xrange(200)])
	print"Case #%d:"%t," ".join(str(x+1)for x in ans)if ans else"IMPOSSIBLE"
