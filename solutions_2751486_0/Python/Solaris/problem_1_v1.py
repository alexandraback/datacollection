#!/usr/bin/env python
import os
import sys
import time
#from   mpmath import     mp
#mp.dps = 100

tStart = time.time()

filename = 'input.txt'
filename = 'A-small-attempt0.in'

ifile = open(filename)
data  = ifile.read()
ifile.close()

lines   = data.splitlines()
n_cases = int(lines[0])
lines   = lines[1:]

print '\n n_cases = ', n_cases
print ''

verbose = 0
 
#--------------------------------------------------------------------------------
def n_value(N,vector):


  if len(vector) < N:
    return 0

  burst_start = 0
  burst_end   = -1
  n_consonant = 0
  for k,x in enumerate(vector):
    if x == 1:
      if n_consonant == 0:
        burst_start = k
      n_consonant += 1
      if n_consonant >= N:
        burst_end = k
        break
    else:
      n_consonant = 0
  if burst_end == -1:
    return 0

  n_cases  = (burst_start+1)*(len(vector)-burst_end)
  vector   = vector[burst_start+1:]
  n_cases += n_value(N,vector)

  return n_cases


#--------------------------------------------------------------------------------
vowels = ['a','e','i','o','u']

cases = []
for nc in xrange(n_cases):
  line  = lines[0].split()
  name  = line[0]
  N     = int(line[1])
  lines = lines[1:]

  vector = [int(not name[k] in vowels) for k in xrange(len(name))]

  result = n_value(N,vector)

  if verbose == 1:
    print 'N = %3d   n-value = %4d     name = %s '%(N,result,name)

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



