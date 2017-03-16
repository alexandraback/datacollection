#!/usr/bin/python
import sys


inp = [l.strip() for l in sys.stdin if l.strip()!='']
T = int(inp[0])
l = 1
for tt in range(T):
  ns = [ int(x) for x in inp[l].split(" ")]
  #print ns
  N = ns[0]
  S = ns[1]
  p = ns[2]
  ts = ns[3:]
  #print S,p,ts
  safe = max(0,3*p-2)
  surp = max(1,safe-2)
  #print 'safe',safe,'surp',surp
  nsf=0
  nsp=0
  for t in ts:
  	if t>=safe:
  		nsf+=1
  	elif t>=surp:
  		nsp+=1

  l += 1
  resp = nsf + min(nsp,S)
  #print(nsf,nsp,resp)
  print "Case #%d: %d" % (tt+1, resp)

