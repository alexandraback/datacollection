#!/usr/bin/env python
import os
import sys
import time
#import psyco
#psyco.full()

tStart = time.time()

#filename = 'input.txt' 
filename = 'B-small-attempt0.in'

ifile = open(filename)
data  = ifile.read()
ifile.close()

lines   = data.splitlines()
n_cases = int(lines[0])
lines   = lines[1:]

print n_cases

cases = []
for nc in xrange(n_cases):
  line  = lines[0].split()
  nrows = int(line[0])
  ncols = int(line[1])
  lines = lines[1:]

  matrix = []
  for k in xrange(nrows):
    matrix.append([int(x) for x in lines[k].split()])

  lines = lines[nrows:]
  cases.append(matrix)
  print nrows, ncols

cases_results = []
for matrix in cases:  
  nrows = len(matrix)
  ncols = len(matrix[0])
  row   = [0 for k in xrange(nrows)]
  col   = [0 for k in xrange(ncols)]

  for k in xrange(nrows):
    for n in xrange(ncols):
      x = matrix[k][n]
      if row[k] < x: row[k] = x
      if col[n] < x: col[n] = x

  matrix_aux = [[0 for k in xrange(ncols)] for n in xrange(nrows)]
  for k in xrange(nrows):
    for n in xrange(ncols):
      matrix_aux[k][n] = min([row[k],col[n]])

  if matrix_aux == matrix: result = 'YES'
  else:                    result = 'NO'
  cases_results.append(result)
  print result

print ''

ofile = open('output.txt','w')  
for k,solution in enumerate(cases_results):
  text = 'Case #%d: %s '%(k+1,solution)
  print text
  ofile.write(text+'\n')
ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     



