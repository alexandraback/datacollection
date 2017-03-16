import sys,math
lines=sys.stdin.readlines();
n=int(lines[0])
for case in range(1, n+1):
	l=lines[case].split();	
	K=int(l[0])
	C=int(l[1])
	S=int(l[2])
	nS=int(math.ceil(float(K)/C))
	
	r=[]
	if S>=nS:
		for i in range(nS):
			startS=i*C
			endS=i*C+C
			s=0
			for j in range(startS, endS):
				if j<K:
					s=s*K+j	
				else:
					s=s*K
			r.append(s)

	sys.stdout.write("Case #%d:" % (case))
	if len(r)==0:
		sys.stdout.write(" IMPOSSIBLE")
	else:
		for e in r:
			sys.stdout.write(" %d" % (e+1))
	print ""
