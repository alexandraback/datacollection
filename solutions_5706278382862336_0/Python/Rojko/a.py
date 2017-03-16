import math

def gcd(p,q):
	if q == 0: return p
	return gcd(q,p%q)	

def normal(p,q):
	g = gcd(p,q)
	return p//g,q//g

def isMocnina(a):
	return ((a & (a-1)) == 0) and a!=0

def vacsie(a,b,c,d):
	return a*d >= b*c

T = int(input())
for t in range(T):
	p,q = map(int,input().split('/'))
	p,q = normal(p,q)
	if not isMocnina(q):
		print("Case #",t+1,": impossible",sep="")
	else:
		x = math.log2(q)
		if 2**x < q:
			x+=1;
		if 2**x > q:
			x-=1;	
		moc,k = 1,0
		while True:
			if vacsie(p,q,1,moc):
				print("Case #",t+1,": ",k,sep="")
				break
			moc*=2
			k+=1
