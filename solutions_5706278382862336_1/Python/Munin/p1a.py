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
def mcd(a,b):
    while a != 0:
        a,b = b%a, a
    return b

def elf(A,B,l, max_level):
  d = mcd(A,B)
  A /= d
  B /= d

  if l >= max_level:
    if A==1 and B==1:
      return l
    else:
      return max_level+1
  else:
    if A==1 and (B==1 or B==2):
      return l+1
    else:
      A *=2
      if A>B: 
        if (elf(A-B,B,l+1,max_level)<=40):
          return l+1
      return elf(A,B,l+1,max_level)


#---------------------------------------------------------------------
# Main
ncases = int(lines[0])
lines  = lines[1:]
for n in xrange(ncases):
  data = lines[n].split('/')
  A = int(data[0])
  B = int(data[1])

  d = mcd(A,B)
  A /= d
  B /= d

  if A*(2**40)%B != 0:
    res = 'impossible'
  else:
    max_level = 40
    for k in xrange(2,40):
      if A*(2**k)%B == 0:
        max_level = k
        break
    l = elf(A,B,0,max_level)
    if l > 40:
      res = 'impossible'
    else:
      res = '%d'%(l)


  # -------------------------------------------------
  res = 'Case #%d: %s'%(n+1, res)
  ofile.write('%s\n'%(res))
  print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     
