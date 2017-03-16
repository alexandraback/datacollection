import random
import sys

def ne(x):
	s=str(x)
	d = len(s)-1
	l = 0
	while(l<len(s)):
		if (ord(s[l])-ord('0')>2): return 10**(d-l+1)*(x/10**(d-l+1)+1)
		l+=1
	return x+1

def pal(x):
	s=str(x)
	for i in xrange(len(s)):
		if (s[i]!=s[len(s)-1-i]): return False
	return True

def rev(s):
	return s[::-1]

mem = set()

def go1(x):
	global mem
	x=int(x)
	if pal(x) and pal(x*x): mem.add(x*x)

def go(l):
	for i in xrange(len(l)):
		l[i]=str(l[i])
	s=''.join(l)
	go1(s+rev(s))
	go1(s+"0"+rev(s))
	go1(s+"1"+rev(s))
	go1(s+"2"+rev(s))




def constr(d):
	for i1 in xrange(d-1):
		for i2 in xrange(i1):
			for i3 in xrange(i2):
				l=[0]*d
				l[0]=1
				l[1+i1]=1
				l[1+i2]=1
				l[1+i3]=1
				go(l)
	for i1 in xrange(d-1):
		for i2 in xrange(i1):
			l=[0]*d
			l[0]=1
			l[1+i1]=1
			l[1+i2]=1
			go(l)
	for i1 in xrange(d-1):
		l=[0]*d
		l[0]=1
		l[1+i1]=1
		go(l)
	l=[0]*d
	l[0]=1
	go(l)
	l[0]=2
	go(l)


for i in xrange(1,1001):
	go1(i)

for i in xrange(1,28):
	#print i
	constr(i)

#print len(mem)
L=sorted(list(mem))


t=int(sys.stdin.readline())
for sdg in xrange(t):
	a,b=map(int,sys.stdin.readline().split())
	w=0
	for e in L:
		if a<=e and e<=b: w+=1
	print "Case #"+str(sdg+1)+": "+str(w)