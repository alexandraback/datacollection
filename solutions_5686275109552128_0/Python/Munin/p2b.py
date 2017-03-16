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
def compute_steps(h):
  
  m = len(h)-1
  while h[m] == 0:
    m -= 1

  best = m
  for move in xrange(2,int(m/2)+1):
    hp          = [x for x in h[:(m+1)]]
    hp[m]       = 0
    hp[m-move] += h[m]
    hp[move]   += h[m]
    time        = h[m] + compute_steps(hp) 
    if time < best:
      best = time

  return best

#---------------------------------------------------------------------
# Main
ncases = int(lines[0])
lines  = lines[1:]
nl = 0
for ncase in xrange(ncases):
  nc = int(lines[nl])
  pp = [int(x) for x in lines[nl+1].split()]
  nl += 2

  if nc != len(pp):
    print '\n\n ERROR \n\n'
    exit(0)

  h = [0 for k in xrange(1001)]
  for x in pp:
    h[x] += 1

  min_r = compute_steps(h)
    
  # -------------------------------------------------
  res = 'Case #%d: %d'%(ncase+1, min_r)
  ofile.write('%s\n'%(res))
  print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     
