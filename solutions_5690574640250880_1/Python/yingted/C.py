#!/usr/bin/pypy
from copy import deepcopy
from heapq import *
import sys
def erode(a,c):
	for i,v in enumerate(a): # i, j-1
		if v!=c and v>0:
			a[i]=v-1
	for i,v in enumerate(a):
		#assert a[i]>=(a[i+1]if i+1<len(a)else 0)
		a[i]=a[min(i+1,len(a)-1)]
def cells(a):
	for i,v in enumerate(a):
		for j in xrange(v):
			yield i,j
def contains(a,i,j):
	return 0<=j<a[i]if 0<=i<len(a) else False
def is_valid(a,c):
	if sum(a)==1:
		assert a[0]==1
		assert c>0
		return True
	eroded=deepcopy(a)
	erode(eroded,c)
	for i,j in cells(a):
		for I in xrange(i-1,i+2):
			for J in xrange(j-1,j+2):
				if contains(eroded,I,J):
					break # found
			else: # not found
				continue
			break # found
		else: #not found
			return False
	return True
def increment(a,c,i):
	if not(0<=i<len(a)):
		return False
	a[i]+=1
	if a[i]>c:
		return False
	if i>0 and a[i]>a[i-1]:
		return False
	if not is_valid(a,c):
		if i==0 and len(a)>1:
			#assert a[0]>a[1] # found our problem
			return increment(a,c,i+1)
		return increment(a,c,i)
	return True
def rindex(a,v):
	for i in reversed(xrange(len(a))):
		if a[i]==v:
			return i
	raise ValueError(v)
def greedy22(r,c,x):
	a=[0]*r
	for i in xrange(r):
		if x>c:
			a[i]+=c
			x-=c
		else:
			a[i]+=x
			x=0
			break
	if a[i]==1:
		a[i]+=1
		a[i-1]-=1
	return a
def greedy(r,c,x):
	#assert r>=3<=c
	#assert 9<=x<=r*c
	if x>=2*c+2:
		return greedy22(r,c,x)
	x0=x
	x-=8
	a=[0]*r
	a[0]=a[1]=3
	a[2]=2
	while x>0:
		x-=1
		if a[2]==2:
			a[2]+=1
		else:
			#assert a[2]==3
			a[2]-=1
			a[0]+=1
			a[1]+=1
			#assert a[0]<=c
	#assert sum(a)==x0,(x0,sum(a),a)
	return a
def solutions(r,c):
	#assert r>=1<=c<=r
	q=[]
	set_q=set()
	def pushvalid(a):
		a=tuple(a)
		if a not in set_q:
			heappush(q,(sum(a),a))
			set_q.add(a)
	for seed in(
		[],
		[1],
		[2,2],
		[c,c],
	):
		if sum(seed)>r*c:
			continue
		if any(v>c for v in seed):
			continue
		dr=r-len(seed)
		if dr<0:
			continue
		seed.extend([0]*dr)
		if is_valid(seed,c):
			pushvalid(seed)
	ret={}
	while q:
		x,a=heappop(q)
		a=list(a)
		#assert x==1 or is_valid(a,c)
		if x not in ret and x!=0:
			#assert x<=r*c
			ret[x]=a
			#yield x,deepcopy(ret[x])
			if x>=9 and c>=3 and r>=3:
				for x in xrange(x+1,r*c+1):
					ret[x]=greedy(r,c,x)
					#yield x,deepcopy(ret[x])
				break
		test_i={0}
		if a[-1]==0:
			i=a.index(0)
			test_i.add(i)
			if i>0:
				test_i.add(i-1)
		if len(a)>=2 and a[-2]==c:
			test_i.add(len(a)-1)
		for i in test_i:
			b=deepcopy(a)
			if increment(b,c,i):
				pushvalid(b)
	return ret
def transpose(sln,c):
	ret=[0]*c
	for i,l in enumerate(sln):
		for j in xrange(l):
			ret[j]=i+1
	return ret,len(sln)
def fmt(sln,c):
	return'\n'.join(''.join('c'if i==j==0 else'.'if j<sln[i]else'*'for j in xrange(c))for i,l in enumerate(sln))if sln else"Impossible"
def main():
	lut={}
	for r in xrange(1,51):
		for c in xrange(1,r+1):
			print>>sys.stderr,"r",r,"c",c
			lut[r,c]=cache=solutions(r,c)
			#print set(cache)
			mirror={}
			for x,a in cache.iteritems():
				#assert x==sum(a),(x,sum(a),a)
				#assert is_valid(a,c)
				b,r2=transpose(a,c)
				#assert r==r2
				#assert sum(a)==sum(b)
				#assert is_valid(b,r)
				mirror[x]=b
			if r!=c:
				lut[c,r]=mirror
	for T in xrange(1,1+int(raw_input())):
		r,c,m=map(int,raw_input().split())
		sln=lut[r,c]
		print"Case #%d:"%T
		a=sln.get(r*c-m)
		if 0 and a is not None:
			#assert is_valid(a,c)
			#assert sum(a)+m==r*c
			from collections import Counter
			count=Counter(fmt(a,c))
			#assert count['c']==1
			#assert count['*']==m
			#assert count['.']+1==r*c-m
			#assert count['\n']+1==r
		print fmt(a,c)
if __name__=="__main__":
	main()
