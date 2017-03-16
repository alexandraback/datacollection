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
		
mh=2500
nm=50
def parse(cin):
	l=[ri(cin), []]
	for k in range( 2*l[0]-1):
		l[1]+=[riv(cin)]
	return l
def fr0(v, p, ids, low = True):
	h=0
	if low:
		h=mh
	i1=-1
	i2=-1
	for i in range(len(v)):
		if i in ids: continue
		cerr.write(str(v[i][p]) + " " + str(h) + "\n")
		if low and v[i][p]< h or not low and v[i][p] > h:
			i1 = i
			i2 = -1
			h=v[i][p]
		elif v[i][p] == h:
			i2 = i
	return i1,i2, h

def find_other(v , val, p, k):
	r1=-1
	r2=-1
	for i in range(len(v)):
		if i==k: continue
		if v[i][p] == val:
			if r1 == -1:	
				r1 = i
			else:
				r2 = i
				return r1, r2
	return r1, r2
			 

def do(l):
	n=l[0]
	v=l[1]
	ids=[]
	m_p = -1
	c=0
	l=0
	m_v = [0 for i in range(n)]
	for i in range(n):
		c,l,m=fr0(v, i, ids)
		if c == -1 or l==-1:
			m_p = i
			
			break
		ids += [c,l]
	l_o = 0
	if c == -1:
		l_0 = l
	else:
		l_0 = c
	m_v[m_p] = v[l_0][m_p]
	ids=[l_0]
	for i in range(n):
		if i == m_p: continue
		c,l,m=fr0(v, i, ids)
		if v[c][m_p] == v[l_0][i]:
			m_v[i] = v[l][m_p]
		else:
			m_v[i] = v[c][m_p]
		ids += [c,l]
	return ' '.join([str(x) for x in m_v])

def main():
	start = time.time()
	T=cin.ri()
	cerr.write("Going to process {} cases\n".format(T))
	k=0
	for Ti in range(1,T+1):
		if math.log(100*Ti/T) > k:
			cerr.write("case {}...".format(Ti))
		print("case #{0}: {1}".format(Ti, do(parse(sys.stdin))))
		if math.log(100*Ti/T) > k:
			k+=1
			cerr.write("duration {}\n".format(time.time()-start))
	cerr.write("duration {0}\n".format(time.time()-start))

if __name__=="__main__":
	main()

