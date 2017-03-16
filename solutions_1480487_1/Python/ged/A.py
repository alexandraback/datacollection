#!/usr/bin/python
import sys

inp = [l.strip() for l in sys.stdin if l.strip()!='']
T = int(inp[0])
l = 1
for t in range(T):
  ss0 = [int(s) for s in inp[l].split(" ") ][1:]
  N = len(ss0)
  ss = zip(ss0, range(len(ss0)))
  ss.sort()
  ps = [0.0]*len(ss)
  vs = [p[0] for p in ss]
  X = sum(ss0)
#  print N,ss,X
  X0=X
  n = 1
  while X>0:
  	while n<N and vs[n-1]==vs[n]:
  		n+=1
#  	print "X=",X," n=",n
  	if n==N:
  		p=float(X)/X0/n
#  		print "* last it p=",p
  		for i in range(N):
  			ps[i] += p
  		X=0
  	else:
  		dif = vs[n]-vs[n-1]
  		if X<dif*n:
  			p = float(X)/X0/n
#  			print "special case p=",p
	  		for i in range(n):
	  			ps[i] += p
  			X=0
  		else:
	  		p = float(dif)/X0
	  		for i in range(n):
	  			ps[i] += p
	  			vs[i] += dif
	  		X-=dif*n
#	  		print "* dif=",dif," p=",p," to n=",n," X=",X

  js = [(ix,p) for ((v,ix),p) in zip(ss,ps)]
  js.sort()
  fs = [str(p*100) for (x,p) in js]
  #fs = ["%0.6f"%(p*100) for (x,p) in js]
  res = " ".join(fs)
#  print "done ",res
  l += 1
  print "Case #%d: %s" % (t+1, res)


