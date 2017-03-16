#!/usr/bin/env python
import os
import sys
import time
#import psyco
#psyco.full()

tStart = time.time()

#filename = 'input.txt'
#filename = 'A-small-attempt1.in'
filename = 'A-large.in'

ifile = open(filename)
data  = ifile.read()
ifile.close()

data  = data.replace('X',' +1 ')
data  = data.replace('O',' -1 ')
data  = data.replace('.','  0 ')

dataX = data.replace('T',' +1 ')
dataO = data.replace('T',' -1 ')

linesX   = dataX.splitlines()
linesO   = dataO.splitlines()
n_cases = int(linesX[0])
linesX   = linesX[1:]
linesO   = linesO[1:]


def game_state(matrix):

  row_sum = [0,0,0,0]
  col_sum = [0,0,0,0]
  dip_sum = [0,0,0,0]
  din_sum = [0,0,0,0]

  board_incomplete = 0
  for k in xrange(4):
    for n in xrange(4):
      x = matrix[k][n]
      row_sum[k]           += x
      col_sum[n]           += x
      dip_sum[(n-k  +4)%4] += x
      din_sum[(3-n-k+4)%4] += x
      if x == 0:
        board_incomplete = 1

  if   ( 4 in row_sum) or ( 4 in col_sum) or ( 4 == dip_sum[0]) or ( 4 == din_sum[0]): return 'X'
  elif (-4 in row_sum) or (-4 in col_sum) or (-4 == dip_sum[0]) or (-4 == din_sum[0]): return 'O'
  elif board_incomplete == 0:                                                          return '='
  else:                                                                                return '.'

final_result = {
  'XX':'X',
  'XO':'E',
  'X=':'X',
  'X.':'X',
  'OX':'E',
  'OO':'O',
  'O=':'O',
  'O.':'O',
  '=X':'X',
  '=O':'O',
  '==':'=',
  '=.':'E',
  '.X':'X',
  '.O':'O',
  '.=':'E',
  '..':'.'}

translate_result = {
  'X':'X won',
  'O':'O won',
  '=':'Draw',
  '.':'Game has not completed'}

cases_results = []
for nc in xrange(n_cases):
  matrixX = [[int(x) for x in line.split()] for line in linesX[:4]]
  matrixO = [[int(x) for x in line.split()] for line in linesO[:4]]
  linesX  = linesX[5:]
  linesO  = linesO[5:]

  rX = game_state(matrixX)
  rO = game_state(matrixO)

  result = final_result[rX+rO]

  print rX, rO, '|', result
  sys.stdout.flush()

  if result == 'E':
    exit(0)

  cases_results += [translate_result[result]]

print ''

ofile = open('output.txt','w')  
for k,solution in enumerate(cases_results):
  text = 'Case #%d: %s '%(k+1,solution)
  print text
  ofile.write(text+'\n')
ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     



