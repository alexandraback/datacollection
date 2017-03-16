from itertools import combinations
from collections import defaultdict
import sys 
def findmatch(s):
    d=defaultdict(list)
    for a in xrange(1,21):
        for b in combinations(s,a):
            x = sum(b)
            if len(d[x]):
                return d[x][0],b
            else: d[x].append(b)
    return 0

def _print(s):
  for j in xrange(len(s)-1):
    print s[j],
  print s[-1]

lines = sys.stdin.readlines()
t = int(lines[0].strip())
for i in xrange(1,t+1):
  nums = map(int,lines[i].strip().split()[1:])
  print "Case #%s:"%i
  a = findmatch(nums)
  if a:
    map(_print,a)
  else:print "Impossible"
