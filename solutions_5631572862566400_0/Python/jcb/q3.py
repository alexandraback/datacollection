#!/usr/bin/python
# -*- coding: UTF-8 -*-

import sys
import random

def solve(g):
  n = len(g)
  
  count = 0
  which_component = {}
  components = {}
  for i in xrange(n):
    if i in which_component:
      continue

    seen_list = []
    seen_set = set()
    current = i
    while True:
      seen_list.append(current)
      seen_set.add(current)
      current = g[current]
      if current in which_component:
        j = which_component[current]
        for k in seen_set:
          which_component[k] = j
          components[j][0].add(k)
        break
      elif current in seen_set:
        cycle_start = 0
        while seen_list[cycle_start] != current:
          cycle_start += 1

        count += 1
        components[count] = (set(), set(), {})
        j = count
        for w in xrange(len(seen_list)):
          k = seen_list[w]
          which_component[k] = j
          components[j][0].add(k)
          if w >= cycle_start:
            components[j][1].add(k)

        break

  #print g
  #print which_component
  #print components

  in_edges = [False] * n
  for i in range(n):
    in_edges[g[i]] = True

  best_open = 0
  best_closed = 0
  for c in components.values():
    if len(c[1]) > best_closed:
      best_closed = len(c[1])

  #print "extras", extras
  #print "best closed", best_closed

  for i in range(n):
    if in_edges[i]:
      continue
    length = 0
    current = i
    c = components[which_component[i]]
    if len(c[1]) > 2:
      continue

    while current not in c[1]:
      current = g[current]
      length += 1

    c[2][current] = max(c[2].get(current, 0), length)

  for c in components.values():
    if len(c[1]) <= 2:
      n = sum(c[2].values())
      best_open += n + len(c[1])

  if True:
    return max(best_closed, best_open)
  
  for i in range(len(g)):
    print "%d->%d" % (i, g[i]),
  print ""
  print components
  print "best closed", best_closed
  print "best open", best_open


  return max(best_closed, best_open)

total = None
count = 0
f = sys.stdin

count = None
length = None
tests = []
for line in sys.stdin:
  if not count:
    count = int(line.strip())
    continue
  elif not length:
    length = int(line.strip())
  else:
    n = [int(x) - 1 for x in line.strip().split()]
    assert len(n) == length
    tests.append(n)
    length = None

if count != len(tests):
  print "Wrong number of test cases"
  sys.exit(0)

counter = 0
for g in tests:
  counter += 1
  #print t
  print "Case #%d: %s" % (counter, solve(g))
  #sys.exit()



