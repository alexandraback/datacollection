#!/usr/bin/env python
import os
import sys
import time

verbose = 0

tStart = time.time()

filename = 'input.txt'
filename = 'B-small-attempt3.in'

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

  E = int(line[0]) # maximum and initial energy
  R = int(line[1]) # regain energy after each activity
  N = int(line[2]) # number of activities

  lines = lines[1:]
  line  = lines[0].split()
  lines = lines[1:]

  V = [int(x) for x in line] # values of each activity

  if len(V) != N:
    print '\n\nERROR\n\n'
    exit(0)

  print '--------------------------------------------'
  print E,R,N,V

  buffer = [[V[k],k] for k in xrange(N)]
  buffer = sorted(buffer, key= lambda x:x[0], reverse=True)

  gain_energy      = 0
  initial_energy   = E
  regain_available = [k for k in xrange(N)]
  ideal_energy     = [E + R*k for k in xrange(N)]

  if verbose:
    print 'regain_available = ', regain_available
  for [v,k] in buffer:
    total_available_energy = initial_energy + R*regain_available[k]
    available_energy       = min([total_available_energy, E])

    if available_energy > 0:
      if available_energy >= R*regain_available[k]:
        initial_energy -= (available_energy - R*regain_available[k])
        for n in xrange(k):
          regain_available[n]  = 0
        for n in xrange(k,N):
          regain_available[n] -= regain_available[k]
  

      elif available_energy < R*regain_available[k]:
        regain_used = int(available_energy/R)
        if regain_used < regain_available[n]:
          regain_used += 1
        for n in xrange(k):
          regain_available[n]  = min([regain_available[n],regain_available[k]-regain_used])
        for n in xrange(k,N):
          regain_available[n] -= regain_used
  
        initial_energy -= max([0,(available_energy - R*regain_used)])

      gain_energy     += available_energy * v

    if verbose:
      print v,k
      print 'ideal_energy     = ', ideal_energy
      print 'available_energy = ', available_energy
      print 'regain_available = ', regain_available
      print 'initial_energy   = ', initial_energy
      print 'gain             = ', gain_energy

  
  cases.append(str(gain_energy))

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



