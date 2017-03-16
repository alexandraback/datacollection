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

def get_perior(data):

  cumprod = 1
  for d in data:
    cumprod = (1-2*int(cumprod<0)) * mul[abs(cumprod)][d]

  dd = cumprod
  nn = 1
  while dd != 1:
    nn += 1
    dd = (1-2*int(dd<0)) * (1-2*int(cumprod<0)) * mul[abs(dd)][abs(cumprod)]

  return nn, cumprod

#---------------------------------------------------------------------
# Constants

# 1->1  2->i  3->j  4->k
mul = [[],[0,1,2,3,4],[0,2,-1,4,-3],[0, 3,-4,-1, 2], [0,4,3,-2,-1]]

#---------------------------------------------------------------------
# Main
ncases = int(lines[0])
lines  = lines[1:]
for ncase in xrange(ncases):
  data = [int(x) for x in lines[0].split()]
  L = data[0]
  X = data[1]
  text = lines[1]
  lines = lines[2:]

  if L*X < 3:
    resultado = 'NO'
  else:
    data   = [2*int(x=='i')+3*int(x=='j')+4*int(x=='k') for x in text]

    period, factor = get_perior(data)

    n_prod  = 0

    cumprod = 1
    state   = 2
    ready   = 0
    nn      = 0
    n_state = 0
    while nn < X and ready == 0:
      nn += 1
      for d in data:
        cumprod = (1-2*int(cumprod<0)) * mul[abs(cumprod)][d]

        if cumprod == state and state <= 4:
          state   += 1
          cumprod  = 1
          n_state  = 0

      n_state += 1
      if (state == 5) or (n_state > period+1):
        ready = 1

    if state == 5 and nn < X:
      for kk in xrange((X-nn)%period):
        cumprod = (1-2*int(cumprod<0)) * (1-2*int(factor<0)) * mul[abs(cumprod)][abs(factor)]
        
      
    if cumprod == 1 and state == 5:
      resultado = 'YES'
    else:
      resultado = 'NO'

  # -------------------------------------------------
  res = 'Case #%d: %s'%(ncase+1, resultado)
  ofile.write('%s\n'%(res))
  print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     
