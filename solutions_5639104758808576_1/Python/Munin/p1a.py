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



#---------------------------------------------------------------------
# Main
ncases = int(lines[0])
lines  = lines[1:]
for n in xrange(ncases):
  data = [x for x in lines[n].split()]
  data = [int(data[1][k]) for k in xrange(len(data[1]))]

  nn = 0
  np = 0
  for k,x in enumerate(data):
    if np >= k:
      np += x
    else:
      nn += k-np 
      np  = k+x
      


  # -------------------------------------------------
  res = 'Case #%d: %d'%(n+1, nn)
  ofile.write('%s\n'%(res))
  print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     
