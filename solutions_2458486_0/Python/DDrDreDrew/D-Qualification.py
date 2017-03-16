from collections import defaultdict as dd

fin = open('D-small-attempt2.in', 'r').readlines()
fout = open('D-small-attempt2.out', 'wb')
T = int(fin[0].strip())

j = 1
for i in xrange(1,T+1):
	chests = dd(set)
	inc = dd(set)
	[K,N] = [int(x) for x in fin[j].strip().split(' ')]
	order = []
	left = set(range(N))
	keys = [int(x) for x in fin[j+1].strip().split(' ')]
	kin = [[int(x) for x in fin[k].strip().split(' ')[2:]] for k in xrange(j+2,j+2+N)]
	lock = [int(fin[k][0]) for k in xrange(j+2,j+2+N)]
	for b in xrange(N): chests[lock[b]].add(b)
	for b in xrange(N): 
		for k in kin[b]: 
			for c in chests[k]:	
				if b != c: inc[c].add(b)
	
	# OPEN CHEST WITH LOWEST NUMBER OF INCOMING EDGES
	opened = True
	while opened:
		sac = sorted([(len(inc[b]),b) for b in left])
		opened = False
		for bin,b in sac:
			if lock[b] in keys:
				opened = True
				order.append(b+1)
				left.discard(b)
				keys.remove(lock[b])
				keys += kin[b]
				for k in kin[b]: 
					for c in chests[k]: inc[c].discard(b)
				break
	j += N+2
	if len(left)>0: fout.write('Case #{}: {}\n'.format(i, 'IMPOSSIBLE'))
	else:			fout.write('Case #{}: {}\n'.format(i, ' '.join([str(x) for x in order])))
