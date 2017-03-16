#!/usr/bin/python
# -*- coding: UTF-8 -*-

import sys
import fractions


def solve(f, c):
  #parse
  k, l, s = [int(x) for x in f.readline().strip().split()]

  keyboard = f.readline().strip()
  target = f.readline().strip()

  if len(keyboard) != k or len(target) != l:
    print "Malformed line:", k, l, s
    sys.exit(0)

  #if count != 100: return 0

  #solve
  #print keyboard, target, s

  keys = {}
  for x in keyboard:
    if x not in target: x = '?'
    keys[x] = keys.get(x, 0) + 1
  for x in keys:
    keys[x] = float(keys[x]) / k
  #print keys

  for x in target:
    if x not in keys:
      return 0.0

  overlaps = set()#[0,]

  for x in xrange(len(target)-1):
    if target[:x+1] == target[-x-1:]:
      overlaps.add(x+1)

  max_len = l - (max(overlaps) if overlaps else 0)
  overlaps.add(0)
  #print overlaps, max_len

  p = 1.0
  o = {}
  for i in xrange(len(target)-1,-1,-1):
    p *= keys[target[i]]
    if i in overlaps:
      o[i] = p

  seen_postfixes = set()
  to_delete = set()
  #print o
  for x in sorted(o.keys(), reverse = True):
    #print " "
    #print x
    postfix = target[x:]  
    seen = False
    #print postfix, target[x:]
    for y in seen_postfixes:
      #print y, postfix
      if postfix[:len(y)] == y:
        #print "deleting", x
        del o[x]
        break
    seen_postfixes.add(postfix)

  #print o
  #print "SDFSDF"

  max_hits = 1 + (s-l)/max_len

  #print max_len, max_hits 

  #probabilistic case
  p_hits = 0
  
  #print keys, target

  #print o, p
  def prob(n, finished):
    #print n, l
    if n <= 0:
      return 0
  
    result = 0
    if finished:
      for x in o.keys():
        if o[x] <= n:
          #print o[x]
          result += o[x] * (1 + prob(n-len(target) + x, True))
    #print "**", result 
    else:
      result += p * (1 + prob(n-len(target), True))

    if len(target) < n:
      result += (1 - keys[target[0]]) * prob(n-1, False)
    
    #print n, finished, result
    return result
    #result = reduce(lambda x,y: x*y
    
  x = prob(s, False)
  #print x
  #print " "
  #print max_hits, x

  return max_hits - x


total = None
count = 0
f = sys.stdin
while f:
  if not total:
    total = int(f.readline().strip())
    continue
  elif count < total:
    count += 1
    print "Case #%d: %s" % (count, solve(f, count))
  else:
    break

if count < total:
  print "Wrong number of test cases"
  sys.exit(0)

