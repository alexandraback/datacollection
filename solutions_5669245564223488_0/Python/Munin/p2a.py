#!/usr/bin/env python
import os
import sys
import time

tStart = time.time()

#---------------------------------------------------------------------

ifilename = 'input.in'
ofilename = 'results.out'

args = sys.argv
if len(args) > 1:
  ifilename = args[1]
if len(args) > 2:
  ofilename = args[2]

#---------------------------------------------------------------------
 
ifile = open(ifilename,'r')
data  = ifile.read()
ifile.close()
lines = data.splitlines()

ofile = open(ofilename, 'w')

#---------------------------------------------------------------------
# Functions
def checkw(w):
  w = [c for c in w]
  k = 0
  while k < len(w)-1:
    if w[k] == w[k+1]:
      w = w[:k] + w[k+1:]
    else:
      k += 1
  w.sort()
  for k in xrange(len(w)-1):
    if w[k] == w[k+1]:
      return 0
  return 1

def countcases(words):
  #print words
  return 0
  if len(words) == 0:
    return 0
  elif len(words) == 1:
    return checkw(words[0])
  else:
#    cs = list(set([c for c in words[0]]))
#    w1 = []
#    w2 = []
#    for w in words:
#      cis = 0
#      for c in cs:
#        if c in w:
#          cis = 1
#          break
#      if cis==1:
#        w1 += [w]
#        cs  = list(set(cs)|set([c for c in w]))
#      else:
#        w2 += [w]
#    if len(w1)>1 and len(w2)>1:
#      return 2*countcases(w1)*countcases(w2)
#    else:
    w1 = words[0]
    N = 0
    conection = 0
    for k in xrange(1,len(words)):
      if w1[-1] == words[k][0]:
        conection = 1
        N += countcases([w1+words[k]] + words[1:k] + words[k+1:])
      if w1[0] == words[k][-1]:
        conection = 1
        N += countcases([words[k]+w1] + words[1:k] + words[k+1:])
    if conection == 0:
      p = 0
      for c in list(set([x for x in w1])):
        for w in words[1:]:
          if c in w:
            p = 1
            break
        if p==1:
          break
      if p==0:
        if checkw(w1) == 1:
          N += 2*countcases(words[1:])
    return N
      

#---------------------------------------------------------------------
# Main
ncases = int(lines[0])
lines  = lines[1:]
for n in xrange(ncases):
  N = int(lines[0])
  words = lines[1].split()
  lines = lines[2:]

#  for k in xrange(len(words)):
#    if len(words[k]) > 2:
#      words[k] = words[k][0]+words[k][-1]

  cases = countcases(words)

  # -------------------------------------------------
  res = 'Case #%d: %d'%(n+1, cases)
  ofile.write('%s\n'%(res))
  print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     
