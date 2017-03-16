#!/usr/bin/env python
import os
import sys
import time

tStart = time.time()

#---------------------------------------------------------------------

ifilename = 'p02_input01.txt'
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

ncases = int(lines[0])
for n in xrange(ncases):
  data = lines[n+1].split()
  C = float(data[0])
  F = float(data[1])
  X = float(data[2])

  D         = 2.0
  cum_time  = 0.0
  best_time = X/D
  while cum_time < best_time:
    cum_time += C/D
    D        += F
    new_time  = cum_time + X/D
    if best_time > new_time:
      best_time = new_time

    if (X/D) < 1e-9:
      break

  res = 'Case #%d: %.7f'%(n+1,best_time)
  ofile.write('%s\n'%(res))
  print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     
