#!/usr/bin/python
# -*- coding: utf-8 -*-

import itertools

f = open("C.small","r");

def readInts():
  return map(int, f.readline().split())

caseCnt = int(f.readline())

class Town:
  def __init__(self):
    self.out = []
    self.zipcode = "UNDEF"

towns = []

pos = 0
def bkt(flightplan, currIdx):
  global pos
  #print (flightplan, pos, currIdx)
  
  # finished?
  if currIdx != flightplan[pos]:
    #print "should not happen: wrong city"
    return False
  
  if pos == len(flightplan) - 1:
    return True
  
  # try to reach next city
  curr = towns[currIdx]
  
  oldpos = -1
  while(oldpos != pos):
    oldpos = pos
    for next in curr.out:
      nextIdx = flightplan[pos + 1]
      if next == nextIdx:
        pos += 1
        #print "call@", currIdx
        if bkt(flightplan, nextIdx):
          return True
        break
    #print "reloop@", currIdx
  
  #print "false"
  return False
    

for caseNr in range(1, caseCnt + 1):
  del towns[0:len(towns)]
  
  n, m = readInts()
  
  for x in xrange(n):
    towns.append(Town())
    towns[x].zipcode = f.readline().strip()
    
  for x in xrange(m):
    u, v = readInts()
    u -= 1
    v -= 1
    towns[u].out.append(v)
    towns[v].out.append(u)
  
  #for u in xrange(n):
  #  print u, towns[u].zipcode, towns[u].out
  
  rng = range(n)
  beststring = "XXXXX" * n
  for flightplan in itertools.permutations(rng):
    #print "---"
    
    zipstring = ""
    for x in flightplan:
      zipstring += towns[x].zipcode
      
    if zipstring > beststring:
      continue
     
    pos = 0
    possible = bkt(flightplan, flightplan[0])
    
    if not possible:
      continue
    
    
    #print "Flightplan:", map(lambda x: x + 0, flightplan)
    #print possible
    #print zipstring
    
    if zipstring < beststring:
      beststring = zipstring
    
  #go for it
  print "Case #" + str(caseNr) + ": " + beststring
