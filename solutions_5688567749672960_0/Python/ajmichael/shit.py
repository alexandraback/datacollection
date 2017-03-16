#!/usr/bin/env python
import sys
from copy import copy
from Queue import Queue

def options(x):
  return [x+1,int(str(x)[::-1])]

def calc(n):
  pass
  


if len(sys.argv) != 2:
  print 'Usage: python shit.py <input file>'

with open(sys.argv[1]) as f:
  testcases = map(int, f.readlines()[1:])

remaining = set(testcases) 

found = {1:1}
if 1 in remaining:
  remaining.remove(1)
  
iters = 1
currQ = Queue()
currQ.put(1)
while remaining:
  iters = iters+1
  nextQ = Queue()
  while not currQ.empty():
    x = currQ.get()
    if (x+1) not in found:
      found[x+1] = iters
      nextQ.put(x+1)
      if (x+1) in remaining:
        remaining.remove(x+1)
    y = int(str(x)[::-1])
    if y not in found:
      found[y] = iters
      nextQ.put(y)
      if y in remaining:
        remaining.remove(y)
  currQ = nextQ

count = 1
for n in testcases:
  print 'Case #'+str(count)+': '+str(found[n])
  count = count + 1 

"""
    text = map(lambda x: x.strip(), f.readlines())
    numTestcases = int(text[0])
    testcases = zip(
        (int(z) for z in text[1::2]),
        ([int(z) for z in x.split()] for x in text[2::2]))
"""
"""
# for some reason, collections.Counter isn't hashable.
# disclaimer: this class is not safe at all for mutations
class HCounter(Counter):
    def __hash__(self):
        return hash(frozenset(self))
    def alts(self):
        key = max(self)
        for delta in range(1, key//2):
            alt = copy(self)
            if alt[key] > 1:
                alt[key] -= 1
            else:
                del alt[key]
            alt[key-delta] += 1
            alt[delta] += 1
            yield alt



# memoize all the things
memo = {}
def diningTime(pset_):
    pset = copy(pset_)  
    if pset not in memo:
        naive = max(pset)
        if naive <= 2:
            memo[pset] = naive
        else:
            memo[pset] = min(naive,1+miin(diningTime(z) for z in pset.alts()))
    return memo[pset]


def miin(x):
    1000000000 if len(x) == 0 else min(x)


tc = 1
for (d, plist) in testcases:
    print 'Case #'+str(tc)+': '+str(diningTime(HCounter(plist)))
    tc += 1
"""
