s = {}
ns = {}
for i in xrange(11):
	for j in xrange(i, 11):
		if j > i+2:
			continue
		for k in xrange(j, 11):
			if k > i+2:
				continue
			t = (i,j,k)
			if k-i==2:
				assert i+j+k not in s
				s[i+j+k]=t
			else:
				assert i+j+k not in ns
				ns[i+j+k]=t
#print s,len(s)
#print ns,len(ns)
#for i in xrange(31):
	#if i in s and i in ns:
		#print i,
#print
tn = input()
for loop in xrange(1,tn+1):
	line = [int(x) for x in raw_input().split()]
	N=line[0]
	S=line[1]
	p = line[2]
	A = line[3:]
	A.sort()
	R = 0
	for i in reversed(xrange(N)):
		x = A[i]
		nsm = max(ns[x])
		if x not in s:
			if nsm >= p:
				R += 1
		else:
			sm = max(s[x])
			if nsm >= p:
				R += 1
			elif sm >= p and S > 0:
				R += 1
				S -= 1
	print 'Case #%d:'%loop,
	print R


