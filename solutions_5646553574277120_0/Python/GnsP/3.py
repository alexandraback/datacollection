def _find(val, v):
	if len(val) == 1:
		return v==val[0]
	if v in val:
		return True
	else:
		for x in val:
			m=val[:]
			del(m[m.index(x)])
			if _find(m, v-x ):
				return True
		return False


T=int(input())
for tc in range(1,T+1):
	[c,d,v]=[int(x) for x in input().split()]
	val = [int(x) for x in input().split()]
	count = 0
	for i in range(1,v+1):
		if not _find(val, i):
			count+=1
			val.append(i)
	print('Case #{_t}: {_s}'.format(_t=tc, _s=count))

