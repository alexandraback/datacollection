
def get_minute(pl):
	q=[]	#queue
	q.append(pl)
	while len(q)>0:
		#print 'current queue : '+str(q)
		v = q.pop(0)	#vertex

		vn = list(v[1:])
		half = vn[0]/2
		vn[0] -= half
		vn.append(half)
		vn.sort(reverse=True)
		vn.insert(0,v[0]+1)	#depth(minute)
		if len(vn) == 1:
			return vn[0]
		q.append(vn)

		for div in range(2,half):
			vn = list(v[1:])
			vn[0] -= div
			vn.append(div)
			vn.sort(reverse=True)
			vn.insert(0,v[0]+1)
			if len(vn) == 1:
				return vn[0]
			q.append(vn)

		vn = list(v[1:])
		for i in range(len(vn)):
			vn[i] -= 1
			if(vn[i]==0):
				vn = vn[:i]
				break
		vn.insert(0,v[0]+1)	#depth(minute)
		if len(vn) == 1:
			return vn[0]
		q.append(vn)
		
	return 0

t = int(raw_input(''))
for c in range(t):
	d = int(raw_input(''))
	pl_r = raw_input('').split(' ')[:d]
	pl = []
	for p_r in pl_r:
		pl.append(int(p_r))
	pl.sort(reverse=True)
	pl.insert(0,0)	#depth(minute)
	#print pl
	print "Case #%d: %d"  % (c+1, get_minute(pl))
