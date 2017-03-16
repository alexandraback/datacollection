import ahocorasick
import itertools
import re

def solve(T):
  print "Case #%d:"%(T+1),
  K,W,L= map(int,raw_input().split())
  key = raw_input()
  word = raw_input()
  tree = ahocorasick.KeywordTree()
  tree.add(word)
  tree.make()
  
  MAX = 0
  num = K**L
  SUM = 0
  for n in itertools.product(key, repeat=L):
    mam = "".join(n);
    ter = len(re.findall('(?=%s)'%word, mam))
    
    SUM+=ter
    MAX= max(MAX,ter)
  
  print "%.8f"%(MAX-((SUM+0.0)/num))
  
  
T = int(input())
for x in xrange(T):
  solve(x)
