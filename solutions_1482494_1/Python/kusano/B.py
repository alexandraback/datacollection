for test in range(input()):
	N = input()
	L = [map(int,raw_input().split())for i in xrange(N)]
	C = [0]*N
	star = 0
	turn = 0
	while True:
		t02 = -1
		for i in xrange(N):
			if C[i]==0 and star>=L[i][1]:
				t02 = i
		t12 = -1
		for i in xrange(N):
			if C[i]==1 and star>=L[i][1]:
				t12 = i
		t01 = -1
		for i in xrange(N):
			if C[i]==0 and star>=L[i][0] and (t01==-1 or L[i][1]>L[t01][1]):
				t01 = i
				
		if t02>=0:
			t = t02
			l = 2
		elif t12>=0:
			t = t12
			l = 2
		elif t01>=0:
			t = t01
			l = 1
		else:
			break
		
		star += l-C[t]
		C[t] = l
		turn += 1
	print "Case #%s: %s"%(test+1,turn if min(C)==2 else "Too Bad")
