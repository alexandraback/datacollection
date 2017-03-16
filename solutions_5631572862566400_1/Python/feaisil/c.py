#!/usr/bin/env python3

import sys,time, math
cin=sys.stdin
cerr=sys.stderr
cout=sys.stdout

def rl(cin):
	"""readline and remove \n"""
	return cin.readline()[:-1]
cin.rl=lambda:rl(cin)
def rs(cin):
	return cin.rl().split()
cin.rs=lambda:rs(cin)
def ri(cin):
	return int(cin.rl())
cin.ri=lambda:ri(cin)
def riv(cin):
	return [int(x) for x in rs(cin)]
cin.riv=lambda:riv(cin)
def rf(cin):
	return float(cin.rl())
cin.rf=lambda:rf(cin)
def rfv(cin):
	return [float(x) for x in rs(cin)]
cin.rfv=lambda:rfv(cin)
def rev(i):
	o=[]	
	for x in range(1,1+len(i)): o+=[i[-x]]
	return o
def revs(s):
	return ''.join(rev(s))	
def isPrime(n):
	for i in range(2, int(math.sqrt(n))):
		if not i%n:
			return true
		

def parse(cin):
	l=[ri(cin), cin.riv()]
	return l

def co(p, f, n, o=-1 ):
	c=f.count(p)
	if o>-1 and c == 1:
		return 0 # the value will be  == o
	i=0
	m=0
	print('c', c, p)
	for k in range(c):
		i=f.index(p,i)
		if i==o:
			i+=1
			continue
		print("a", p, i, m, o)
		m_l = co(i,f,n )
		print("b",m_l, p, i, m, o)
		if m_l > m: m=m_l
		i+=1
	if o==-1:
		return m+1
	else:
		return m
	
		
def do(l):
	n=l[0]
	f=l[1]
	f=[f[x]-1 for x in range(n)]
	ids=[]
	lids=[]
	m=0
	print (f)
	pairmx=0
	for i in range(n):
		print (i)
		if i in ids:
			print("skipped")
			continue
		k = i
		cm = 1 
		lids = [i]
		while f[k] not in lids:
			print(k,'->', f[k])
			cm+= 1
			k=f[k]
			lids +=[k]
		print(k,'->', f[k])
		if f[k] == i:
			ids += lids
			if cm == 2:
				# special case where we have a 2 pups cycle
				p1 = i
				p2 = f[i]
				cm+=co(p1, f, n, p2)
				cm+=co(p2, f, n, p1)
				pairmx+=cm
			if cm > m:
				m=cm
	if pairmx>m:
		m=pairmx	
	return str(m)

def main():
	start = time.time()
	T=cin.ri()
	print("Going to process {} cases\n".format(T))
	k=0
	for Ti in range(1,T+1):
		if math.log(100*Ti/T) > k:
			print("case {}...".format(Ti))
		cerr.write("case #{0}: {1}\n".format(Ti, do(parse(sys.stdin))))
		if math.log(100*Ti/T) > k:
			k+=1
			print("duration {}".format(time.time()-start))
	print("duration {0}".format(time.time()-start))

if __name__=="__main__":
	main()

