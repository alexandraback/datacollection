from template import * 

readFile('r23')

def solve(i,l,v,chain = False):
	global m
	#print "Solve ",i,l,m
	pp=None
	p=None
	z=i
	while v[z] is False:
		v[z]=True
		l+=1
		if not p is None:
			pp=p
		p=z
		z = f[z]
		#print pp, p, z
	if z == i and not chain:
		m = max(m,l)
	if pp == z:
		#print p, b[p]
		m = max(m,l)
		if p in b:
			l, v = back(l,v,p)
		m = max(m,l)
		#print z
		for k in range(N):
			if not v[k+1]:
				bv = list(v)
				solve(k+1,l,bv,True)

def back(l,v,p):
	global m
	bestl = l
	for q in b[p]:
		bv = list(v)
		nl = l
		if bv[q] is False:
			bv[q]=True
			nl+=1
			if q in b:
				nl, bv = back(nl, bv,q)
		if nl>bestl:
			bestl = nl
			v = bv
	return bestl, v

def main():
	global v,m,f,b,N 
	T = readInt()
	for t in range(T):		
		N = readInt()
		f={}
		b={}
		for i in range(N):
			k = readInt()		 
			f[i+1]=k
			if not k in b:
				b[k] = []
			b[k].append(i+1)
			#print "SAVE", k, i+1
		m=0
		for g in range(N):
			v = [False for k in range(N+1)]
			solve(g+1,0,v)		
		print N,f
		answerLn("Case #"+str(t+1)+": "+str(m))
		
main()