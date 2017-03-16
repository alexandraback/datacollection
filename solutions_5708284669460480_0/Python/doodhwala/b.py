def countmaadi(search, patt):
	cnt = 0
	idx = 0
	while True:
		idx = search.find(patt, idx)
		if idx >= 0:
			cnt += 1
			idx += 1
		else:
			break
	return cnt

def genPerm(L, k):
	c = 1
	for i in range(len(L)):
		if(c == 1 and L[len(L) - i - 1] == k-1):
			L[len(L) - i - 1] = 0
		elif(c == 1):
			L[len(L) - i - 1] += 1
			c = 0
			break
	if(c == 1):
		L[0] = k
	return L

def getStr(kb, L):
	ms = ''
	for x in L:
		ms += kb[x]
	return ms

for cases in range(input()):
	k,l,s = raw_input().split()
	k,l,s = int(k),int(l),int(s)
	
	keyboard = raw_input()
	patt = raw_input()
	ans = 0.0
	
	mval = 0
	total = 0
	permcount = 0
	
	L = [0 for x in range(s)]
	
	while k not in L:
		perm = getStr(keyboard, L)
		ctr = countmaadi(perm, patt)
		mval = max(mval, ctr)
		total += ctr
		permcount += 1
		L = genPerm(L, k)
		
	ans = mval - (total+0.0)/permcount
	
	print 'Case #'+str(cases+1)+':', ans
