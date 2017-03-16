# Recycled Number

T = int(raw_input())
for t in range(T):
	a,b = raw_input().split()
	assert len(a) == len(b), 'lengths of two numbers are not the same!'
	ndigits = len(a)
	
	lo, up = int(a), int(b)
	assert lo <= up
	ans = 0
	for i in range(lo, up):
		i = str(i)
		ret = set()
		for j in range(1, ndigits):
			tmp = i[j:]+i[0:j]
			if i < tmp <= b: ret.add(tmp)
		ans += len(ret)
	
	print 'Case #%d: %d' %(t+1, ans),
	if t < T-1: print
	