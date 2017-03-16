def func(N, l):
	l2 = []
	d = {}
	for in_l in l:
		for c in in_l:
			if c not in d:
				d[c]=0
			d[c] += 1
			
	for c in d.keys():
		if d[c]%2!=0:
			l2 += [int(c)]
			
	l2.sort()
	return ' '.join(str(x) for x in l2)

	
T = int(raw_input())
for i in range(T):
	N = int(raw_input())
	l = []
	for j in range(2*N-1):
		l += [raw_input().split()]
		
	print 'Case #%d: %s' % (i+1, func(N, l))