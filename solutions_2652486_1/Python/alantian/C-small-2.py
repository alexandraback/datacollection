import math

def rl():
	return map(int,raw_input().split())

def GC(s,p):
	x=[]
	for v in s:
		q=v
		c=0
		while q % p == 0:
			q /= p
			c+=1
		x.append(c)
	return sum(x)*1.0/len(x)
	
def go(v,sample):
	res = 0
	for x in sample:
		if v==x:
			res += 1
	#print 'res',v,sample,res
	return res*1.0/len(sample)

def solve(r,n,m,k,sample):
	# assume r=8000,n=12,m=8,k=12
	C2=GC(sample,2)
	C3=GC(sample,3)
	C5=GC(sample,5)
	C7=GC(sample,7)
	
	E5 = int(math.ceil(C5*2))
	E7 = int(math.ceil(C7*2))
	
	best = ()
	best_nn = -1000
	
	for E3 in range(12):
		for E2 in range(12):
			E6 = int(C3*2-E3)
			if E6 < 0:
				continue
			E48_23 = C2*2-E2-E6
			if E48_23 < 0:
				continue
			E4 = int( E48_23*2/5 )
			E8 = int( E48_23*3/5 )
			
			nn = E2+E3+E4+E5+E6+E7+E8
			if abs(nn-n) <= abs(best_nn-n):
				best_nn = nn
				best = (E2,E3,E4,E5,E6,E7,E8)
	
	(E2,E3,E4,E5,E6,E7,E8) = best
	nn = best_nn
	while nn < n:
		E2 += 1
		nn += 1
		if nn == n: break
		E3 += 1
		nn += 1
	
	print '2'*E2+'3'*E3+'4'*E4+'5'*E5+'6'*E6+'7'*E7+'8'*E8
	
def main():
	(T,) = rl()
	for t in range(1,T+1):
		r,n,m,k = rl()
		samples =[]
		for i in range(r):
			samples.append(rl())
		print 'Case #%d:'%(t)
		for sample in samples:
			solve(r,n,m,k,sample)
	
main()