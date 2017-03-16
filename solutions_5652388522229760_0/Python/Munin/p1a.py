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
def get_sol(N):

  if N == 0:
    return 'INSOMNIA'

  digs = range(10)

  M = 0
  while 1:
    M = M+N
    x = M
    while x>0:
      n = x%10
      x = int(x/10);
      if n in digs:
        digs.remove(n)
        if len(digs) == 0:
          return M


#---------------------------------------------------------------------
# Main
ncases = int(lines[0])
lines  = lines[1:]
for ncase in xrange(ncases):
  data  = [int(x) for x in lines[0].split()]
  lines = lines[1:]
  solution = get_sol(data[0])

  # -------------------------------------------------
  res = 'Case #%d: %s'%(ncase+1, solution)
  ofile.write('%s\n'%(res))
  print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     
