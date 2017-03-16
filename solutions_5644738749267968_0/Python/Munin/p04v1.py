#!/usr/bin/env python
import os
import sys
import time

tStart = time.time()

#---------------------------------------------------------------------

ifilename = 'p03_input.in'
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
lines  = lines[1:]
for n in xrange(ncases):
  nbs     = int(lines[0])
  bs1     = [float(x) for x in lines[1].split()]
  bs2     = [float(x) for x in lines[2].split()]
  lines   = lines[3:]

  bs1.sort()
  bs2.sort()

  #print nbs, bs1, bs2

  # --- War Game ------------------------------------
  bs1p = [x for x in bs1]
  bs2p = [x for x in bs2]
  war_naomi_points = 0

  for k in xrange(nbs):
    # --- War Naomi Choose ---
    p1   = bs1p[0]
    bs1p = bs1p[1:]

    # --- War Ken Choose -----
    p2 = bs2p[0]
    for m,x in enumerate(bs2p):
      if x > p1:
        p2 = x
        break
    bs2p.remove(p2)
    
    # --- Point --------------
    if p1 > p2:
      war_naomi_points += 1

  # --- Deceitful War Game --------------------------
  bs1p = [x for x in bs1]
  bs2p = [x for x in bs2]
  deceitful_war_naomi_points = 0

  for k in xrange(nbs):
    # --- Deceitful War Naomi Choose ---
    if bs1p[-1] > bs2p[0]:
      p1_told = bs2p[-1] + 1e-8
      p1 = bs1p[0]
      for m,x in enumerate(bs1p):
        if x > bs2p[0]:
          p1 = x
          break
      bs1p.remove(p1)
    else:
      p1      = bs1p[0]
      bs1p    = bs1p[1:]
      p1_told = p1
    
    # --- War Ken Choose -----
    p2 = bs2p[0]
    for m,x in enumerate(bs2p):
      if x > p1_told:
        p2 = x
        break
    bs2p.remove(p2)
    
    # --- Point --------------
    if p1 > p2:
      deceitful_war_naomi_points += 1

  # -------------------------------------------------

  res = 'Case #%d: %d %d'%(n+1, deceitful_war_naomi_points, war_naomi_points)
  ofile.write('%s\n'%(res))
  print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     
