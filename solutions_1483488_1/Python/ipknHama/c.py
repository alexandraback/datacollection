import time
st=time.time()
prepare = {}
for i in xrange(1,2000001):
	s = str(i)
	nset = set()
	nset.add(i)
	prepare[i] = nset
	for j in xrange(1,len(s)):
		if s[j] == '0':
			continue
		s2 = s[j:]+s[:j]
		x = int(s2)
		nset.add(x)
		prepare[x] = nset

tn = input()
for loop in xrange(1,tn+1):
	d = {}
	line = [int(x) for x in raw_input().split()]
	A,B=line
	l = len(str(A))
	c = 0
	st=time.time()
	for i in xrange(A,B+1):
		if i in d:
			continue
		#s = str(i)
		#nset = None
		#for j in xrange(1,len(s)):
			#if s[j] == '0': 
				#continue
			#s2 = s[j:]+s[:j]
			#x = int(s2)
			#if x >= A and x <= B:
				#if not nset:
					#nset = set()
				#d[x] = 1
				#nset.add(x)
		nset = set()
		for x in prepare[i]:
			if x >= A and x <= B:
				nset.add(x)
				d[x] = 1
		if nset:
			nset.add(i)
			count = len(nset)-1
			c += count*(count+1)//2
		#print i, nset
	print 'Case #%d:'%loop,c
				


