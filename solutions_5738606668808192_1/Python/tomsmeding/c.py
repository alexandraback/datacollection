#!/usr/bin/env python3

import sys

N=32
J=500


def ipow(b,e):
	if e==0: return 1
	if e==1: return b
	r=b
	while e>1:
		r*=b
		e-=1
	return r

# print("Reading primes.txt... ",end="",file=sys.stderr)
# sys.stderr.flush()
# with open("primes.txt","r") as f:
# 	primes=[int(x) for x in f.read().split("\n")[:-1]]
# print("done",file=sys.stderr)
primes=[2]

def getdiv(n):
	for i in range(primes[-1],n+1):
		if checknewprime(i):
			primes.append(i)
	if binfind(primes,n)!=None:
		return None
	for p in primes:
		if n%p==0:
			return p
	return None

def getdivlim(n,lim):
	while len(primes)<lim:
		i=primes[-1]+1
		while not checknewprime(i): i+=1
		primes.append(i)
	for i in range(lim):
		if n%primes[i]==0:
			return primes[i]
	return None

def checknewprime(n): #isprime that only works for the very next prime after primes[]
	# print("*",end="",file=sys.stderr)
	sys.stderr.flush()
	for p in primes:
		if n%p==0: return False
	return True

def binfind(l,v):
	L=0
	H=len(l)-1
	if l[0]==v: return l[0]
	if l[-1]==v: return l[-1]
	while L+1<H:
		M=(L+H)//2
		if l[M]==v: return l[M]
		if l[M]<v: L=M
		else: H=M
	if l[L]==v: return l[L]
	if l[H]==v: return l[H]
	return None


def fullsearch():
	midlim=ipow(2,N-2)
	for i in range(0,midlim):
		s=bin(i)[2:]
		jc="1"+"0"*(N-2-len(s))+s+"1"
		divs=[]
		for b in range(2,11):
			div=getdiv(int(jc,b))
			if div==None: break
			divs.append(div)
		if len(divs)==9:
			print(jc," ".join([str(x) for x in divs]))

def simplesearch():
	seen=set()
	midlim=ipow(2,N-2)
	npr=1000
	while True:
		npr+=1 #number of primes to check as divisors
		for i in range(0,midlim):
			s=bin(i)[2:]
			jc="1"+"0"*(N-2-len(s))+s+"1"
			if jc in seen: continue
			divs=[]
			for b in range(2,11):
				div=getdivlim(int(jc,b),npr)
				if div==None: break
				divs.append(div)
			if len(divs)==9:
				print(jc," ".join([str(x) for x in divs]))
				seen.add(jc)
				if len(seen)>=J: return

print("Case #1:")
simplesearch()
