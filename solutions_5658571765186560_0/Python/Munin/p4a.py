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

def get_solution(X,R,C):
  
  ###
  # #
  ##
  if X >= 7:
    return 'RICHARD'

  if (R*C)%X != 0:
    return 'RICHARD'

  #######
  #
  #
  if R+C-1 < X:
    return 'RICHARD'

  ###
  ####
  ###
   #
  if min([R,C])**2 + 2 <= X:
    return 'RICHARD'

  ###
  # # 
  if (R==2 or C==2) and X >= 5:
    return 'RICHARD'

  if X >= 4 and ([R,C]==[2,4] or [R,C]==[4,2]):
    return 'RICHARD'
    
  
#  # split in the maximum dimension 
#  maxD  = max([R,C])
#  minD  = min([R,C])
#
#  if maxD + 2 <= X:
#    n_row = int((X-2)/maxD)
#    res = X - 2 - maxD*n_row
#
#    ready = 0
#    if n_row >= 2:
#      for nr in [n_row, n_row-1]:
#        for r in xrange(1,maxD):
#          M = R*C - (nr+1)*maxD - r
#          while M%X != 0 and M>minD:
#            M -= minD
#          if M%X != 0:
#            ready = 1
#            break
#        if ready == 1:
#          break
#    else:
#      for nr in [n_row]:
#        for r in xrange(1,res+1):
#          M = R*C - (nr+1)*maxD - r
#          while M%X != 0 and M>minD:
#            M -= minD
#          if M%X != 0:
#            ready = 1
#            break
#        if ready == 1:
#          break
#
#    if ready == 1:
#      return 'RICHARD 5'
#          
#  if minD + minD  <= X:
#    n_row = int((X-minD)/minD)
#    res = X - 2 - minD*n_row
#
#    if n_row >= 2:
#      for nr in [n_row, n_row-1]:
#        for r in xrange(1,minD):
#          M = R*C - (nr+1)*minD - r
#          while M%X != 0 and M>minD:
#            M -= minD
#          if M%X != 0:
#            ready = 1
#            break
#        if ready == 1:
#          break
#      if ready == 1:
#        return 'RICHARD 5'
            

  return 'GABRIEL'

#---------------------------------------------------------------------
# Main
ncases = int(lines[0])
lines  = lines[1:]
for ncase in xrange(ncases):
  data  = [int(x) for x in lines[0].split()]
  lines = lines[1:]
  X = data[0]
  R = data[1]
  C = data[2]


  solution = get_solution(X,R,C)

  print ' '*30, X,R,C, ' ---- ', int(solution=='GABRIEL')

  # -------------------------------------------------
  res = 'Case #%d: %s'%(ncase+1, solution)
  ofile.write('%s\n'%(res))
  print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     
