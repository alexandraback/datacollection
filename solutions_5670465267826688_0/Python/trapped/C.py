T = int(raw_input())

mult = {}
mult[(2,3)] = 4
mult[(2,4)] = -3
mult[(3,2)] = -4
mult[(3,4)] = 2
mult[(4,2)] = 3
mult[(4,3)] = -2

def prod(x1, x2):
	if x1*x2 > 0: sign = 1
	else: sign = -1
	x1 = abs(x1)
	x2 = abs(x2)
	if x1 == 1: return sign*x2
	if x2 == 1: return sign*x1
	if x1 == x2: return sign*(-1)
	return sign*mult[(x1,x2)]

memo = {}
def inverse(b,a):
	# returns x s.t. a*x = b
	if abs(a) == abs(b) == 1: return b//a
	if (b,a) in memo: return memo[(b,a)]
	for x in range(1,5):
		if prod(a,x) == b: 
			memo[(b,a)] = x
			return x
		if prod(a,-x) == b: 
			memo[(b,a)] = x
			return -x
	return -1

def pos_j(x1, x2, p1, p2, p, s):
	L = len(p1)
	m = [-1,-1,-1,-1,-1] # 4n + {0, 0, 1,2,3}: 0 has two cases - strict substring of the current string, cross-over substring from 2 strings
	if x1+1 < x2:
		if x1 + 1 == x2 - 1: x = s[x1+1]
		else: x = inverse(p1[x2-1],p1[x1])
		#print "j:",x, s[x1+1]
		if x == 3: m[0] = 0 
	if x1 < L-1: 
		p1n = inverse(p1[L-1], p1[x1])
		#print "p1n",p1n
	else: p1n = 1
	if x2 > 0: p12 = p1[x2-1]
	else: p12 = 1
	x = prod(p1n,p12)
	if x == 3: m[1] = 0
	elif x == -3: m[3] = 0
	x = prod(p1n,p)
	x = prod(x, p12)
	if x == 3: m[2] = 0
	elif x == -3: m[4] = 0
	return m
	

for t in xrange(1,T+1):
	L, X = map(int, raw_input().split())
	s = []
	for x in raw_input().strip():
		if x == 'i': s.append(2)
		elif x == 'j': s.append(3)
		else: s.append(4)
	# i = 2, j = 3, k = 4
	p1 = [0 for _ in range(L)] #cumprod starting from 0 to position
	p = 1 # cumprod
	pos_i = [[],[],[],[]] # positions with 4n+0,4n+1,4n+3 reps
	for i in xrange(L):
		p = prod(p, s[i])
		p1[i] = p
		if p == 2: pos_i[0].append(i)
		if X > 2 and p == -2: pos_i[2].append(i)
	
	# impossible cases
	if p == 1 or len(s) == 1:
		print "Case #%d: NO"%(t)
		continue
	elif p == -1:
		if X%2 == 0:
			print "Case #%d: NO"%(t)
			continue
	else: # p is +-{i,j,k}
		if X%2 == 1 or X%4 == 0:
			print "Case #%d: NO"%(t)
			continue
	
	p2 = [0 for _ in range(L)] #cumprod from position to L-1
	pn = 1
	pos_k = [[],[],[],[]]
	for i in xrange(L-1,-1,-1):
		pn = prod(s[i], pn)
		p2[i] = pn
		if pn == 4: pos_k[0].append(i)
		if X > 1:
			if prod(p2[i],p) == 4: pos_k[1].append(i)
			if prod(p,p1[L-i-1]) == 2: pos_i[1].append(L-i-1)
		if X > 2 and p2[i] == -4: pos_k[2].append(i)
		if X > 3:
			if prod(p2[i],-p) == 4: pos_k[3].append(i)
			if prod(-p,p1[L-i-1]) == 2: pos_i[3].append(L-i-1)
	
	found = False
	#print "here", s
	#print pos_i,pos_k
	for m1 in range(4):
		for x1 in pos_i[m1]:
			for m3 in range(4):
				if m1 + m3 >= X: break
				for x2 in pos_k[m3]:
					#if x2 == 0: continue
					m2 = pos_j(x1, x2, p1, p2, p, s) # returns a 5-tuple of possible 0, 4n, 4n+1, 4n+2, 4n+3
					#print m1,x1, m3, x2, m2
					if m2[0] == 0 and (X - 1 - (m1+m3))%4 == 0:
						found = True
						break
					len2 = X - (m1+m3)
					if m2[1] == 0 and (len2 - 2) >= 0 and (len2 - 2)%4==0:
						found = True
						break
					for m in range(2,5):
						remlen = (len2 - 2 - (m-1))
						if m2[m] == 0 and  remlen >= 0 and remlen%4 == 0:
							found = True
							break
					if found: break
				if found: break
			if found: break
		if found: break
	
	if found: print "Case #%d: YES"%(t)
	else: print "Case #%d: NO"%(t)
