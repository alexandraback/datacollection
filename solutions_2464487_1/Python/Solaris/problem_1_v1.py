#!/usr/bin/env python
import os
import sys
import time
from   mpmath          import     mp
mp.dps = 100

tStart = time.time()

filename = 'A-large.in'

ifile = open(filename)
data  = ifile.read()
ifile.close()

lines   = data.splitlines()
n_cases = int(lines[0])
lines   = lines[1:]

print '\n n_cases = ', n_cases
 

#--------------------------------------------------------------------------------
cases = []
for nc in xrange(n_cases):
  line = lines[0].split()
  
  R = mp.mpf(int(line[0]))
  T = mp.mpf(int(line[1]))

  Tp = T #/ mp.pi
  N1 = 0.25 * (+(4*(R**2)-4*R+8*Tp+1)**0.5 -2*R+1)
  N  = int(N1)

  lines = lines[1:]

  cases.append(str(N))

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



