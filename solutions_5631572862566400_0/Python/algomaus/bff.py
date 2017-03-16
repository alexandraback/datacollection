#! /usr/bin/env python

import networkx as nx # install via pip install networkx

def makeDict(line):
  l = {}
  lineSplitted = line.split(' ')
  n = len(lineSplitted)
  for i in range(n):
    l[i+1] = int(lineSplitted[i])
  return l

def parse(lines):
  t = int(lines[0])
  cases = []
  actLine = 1
  for i in range(t):
    n = int(lines[actLine])
    actLine = actLine + 1
    friends = makeDict(lines[actLine])
    cases.append(friends)
    actLine = actLine + 1
  return cases
  
def valid(circle, friends):
  if len(circle) < 2:
    return True

  if friends[circle[0]] != circle[len(circle)-1] and friends[circle[0]] != circle[1]:
    return False

  for i in range(len(circle) - 2):
    if friends[circle[i+1]] != circle[i] and friends[circle[i+1]] != circle[i+2]:
      return False
      
  if friends[circle[len(circle)-1]] != circle[len(circle)-2] and friends[circle[len(circle)-1]] != circle[0]:
    return False
      
  return True
  
def backtrack(circle, friends, bestlen):
  last = circle[len(circle) - 1] 

  # version 1
  if friends[last] not in circle:
      ca = []
      for c in circle:
        ca.append(c)
      ca.append(friends[last])
      if valid(ca, friends):
        bestlen = len(ca)
      blen = backtrack(ca, friends, bestlen)
      if blen > bestlen:
        bestlen = blen
  #version2
  for a in filter(lambda x: x not in circle, friends):
      if friends[a] == last:
        ca = []
        for c in circle:
          ca.append(c)
        ca.append(a)
        if valid(ca, friends):
          best = len(ca)
        blen = backtrack(ca, friends, bestlen)
        if blen > bestlen:
          bestlen = blen
  return bestlen
  
def solve(friends):
  bestlen = 0
  for i in friends:
    c = []
    c.append(i)
    actlen = backtrack(c, friends, 1)
    if actlen > bestlen:
      bestlen = actlen
  return str(bestlen)
  
#with open('B-large.in', 'r') as f:
with open('C-small-attempt3.in', 'r') as f:
  cases = parse(f.read().splitlines())
for i in range(len(cases)):
  res = solve(cases[i])
  print "Case #" + str(i+1) + ": " + res
