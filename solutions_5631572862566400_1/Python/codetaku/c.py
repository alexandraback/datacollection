#!/usr/bin/env python

import sys
import math
import Queue as q

lib = {} #mutable globals just in case
lst = []

if (len(sys.argv) != 3):
  print "You need 3 args including the file name"

linesPerTest = int(sys.argv[2])

def retOpen(tnum):
  return "Case #" + str(tnum) + ":"

def lstSort(tup):
  return tup[1]

def getEndOfChain(stud,a):
  visited = set()
  next = a
  last = -1
  while next not in visited:
    visited.add(next)
    last = next
    next = stud[next]
  return last # you always need the one that wasn't already visited to work back from

def hasMutualChainEnd(stud,a):
  visited = set()
  next = a
  last = -1
  while next not in visited:
    visited.add(next)
    last = next
    next = stud[next]
  if last == stud[next]:
    return (next,len(visited) - 2) # don't include the mutual pair
  return (-1,0)

def getChainLenIfComplete(stud,a):
  visited = set()
  next = a
  while next not in visited:
    visited.add(next)
    next = stud[next]
  if next == a:
    return len(visited)
  return 0

def runTest(t,lines,output):
  mutualPairs = [] #if one is in, they both have to be in
  maxPerPartner = {}
  n = int(lines[0])
  line = lines[1].split(" ")
  stud = []
  for a in line:
    stud.append(int(a) - 1) #0-index plz
  skip = set()
  for a in range(n):
    if a in skip:
      continue
    if stud[stud[a]] == a:
      skip.add(stud[a])
      mutualPairs.append({a,stud[a]}) #for each mutual pair, either we include or don't, _including_ the longest possible chain that ends at each half of the mutual pair
      maxPerPartner[a] = 0
      maxPerPartner[stud[a]] = 0
  chainStarts = []
  maxi = 0
  for a in range(n):
    check = getChainLenIfComplete(stud,a)
    if check > maxi:
      maxi = check
  for a in range(n):
    check = hasMutualChainEnd(stud,a)
    if check[0] >= 0 and maxPerPartner[check[0]] < check[1]:
      maxPerPartner[check[0]] = check[1]
  comp = 0
  for a in maxPerPartner.keys():
    comp += maxPerPartner[a] + 1
  if comp > maxi:
    maxi = comp
  ret = retOpen(t) + " " + str(maxi) + "\n"
  output.write(ret)
  print ret

with open(sys.argv[1],"r") as file1, open("/home/codetaku/Downloads/output","w") as file2:
  testCase = 1
  lines = file1.readlines()
  numTests = int(lines[0])
  lineno = 1
  while (testCase <= numTests):
    if (linesPerTest > 0):
      runTest(testCase,lines[lineno:lineno + linesPerTest],file2)
      lineno += linesPerTest
    else:
      thisTestLines = int(lines[lineno].split(" ")[0]) + 1
      runTest(testCase,lines[lineno:lineno + thisTestLines],file2)
      lineno += thisTestLines
    testCase += 1






