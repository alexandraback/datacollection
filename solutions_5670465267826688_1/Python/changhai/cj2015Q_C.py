import sys, string

def pow(a, n):
	if a==1: return 1
	if a==-1: return 1 if n%2==0 else -1
	return [1,a,-1,-a][n%4]

#1ijk -> 1234
def multiply(a, b):
	t = [1,2,3,4, 2,-1,4,-3, 3,-4,-1,2, 4,3,-2,-1]
	x = t[(abs(a)-1)*4+abs(b)-1]
	if a*b > 0: return x
	else: return -x
	
def reducible(L,X,S):
	S = S * min(X, 8)
	prod = 1
	idone = False
	jdone = False
	for i in xrange(len(S)):
		#1ijk -> 1234
		b = ord(S[i])-ord("g")
		prod = multiply(prod, b)
		if i==L-1 and pow(prod, X) != -1:
			return "NO"
		if not idone and prod == 2:
			idone = True
		if idone and not jdone and prod == 4:
			jdone = True
		if idone and jdone and i >= L-1:
			return "YES"
	return "NO"
	
f = open(sys.argv[1])
out_fname = sys.argv[1][:-2] + "out"
out = open(out_fname,"w")
T = int(f.readline().strip())

for tc in range(1, T+1):
	L, X = [int(a) for a in f.readline().strip().split()]
	S = f.readline().strip()
	print >>out, "Case #%d: %s"%(tc, reducible(L,X,S))