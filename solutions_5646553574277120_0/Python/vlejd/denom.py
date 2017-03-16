import ahocorasick
import itertools
import re

def posible(coins,V):
  can = set()
  can.add(0)
  for c in coins:
    pom = list(can)
    for n in pom:
      can.add(n+c)
  for x in xrange(V+1):
    if x not in can:
      return False
  return True


def solve(T):
  print "Case #%d:"%(T+1),
  C,D,V= map(int,raw_input().split())
  denom =map(int, raw_input().split())  
  skade =[]
  for x in xrange(V):
    if(x+1) not in denom:
      skade.append(x+1)
  
  for l in xrange(len(skade)+1):
    for comb in itertools.combinations(skade,l):
      if(posible(list(comb)+list(denom),V)):
        print l
        return
  
  
  
T = int(input())
for x in xrange(T):
  solve(x)
