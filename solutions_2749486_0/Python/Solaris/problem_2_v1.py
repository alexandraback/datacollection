#!/usr/bin/env python
import os
import sys
import time
#from   mpmath import     mp
#mp.dps = 100

tStart = time.time()

filename = 'input.txt'
filename = 'B-small-attempt0.in'

ifile = open(filename)
data  = ifile.read()
ifile.close()

lines   = data.splitlines()
n_cases = int(lines[0])
lines   = lines[1:]

print '\n n_cases = ', n_cases

verbose = 0
 
#--------------------------------------------------------------------------------
cases = []
for nc in xrange(n_cases):
  line  = lines[0].split()
  X     = int(line[0])
  Y     = int(line[1])
  lines = lines[1:]

  moves = ''
  for k in xrange(abs(X)):
    if X < 0: moves = moves + 'EW'
    else:     moves = moves + 'WE'
  for k in xrange(abs(Y)):
    if Y < 0: moves = moves + 'NS'
    else:     moves = moves + 'SN'
  result = moves
  cases.append(str(result))

print ''


#--------------------------------------------------------------------------------
print '\n\n--- Results --------------------------------------------------------\n'
ofile = open('output.txt','w')
for k,solution in enumerate(cases):
  text = 'Case #%d: %s '%(k+1,solution)
  print text
  ofile.write(text+'\n')
ofile.close()

print '\n Run time = ' + str((time.time() - tStart))



