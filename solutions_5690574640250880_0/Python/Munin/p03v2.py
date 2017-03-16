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

def print_case_M0(R,C):
  text = ''
  for r in xrange(R):
    if r != R-1:
      text += '.'*C + '\n' 
    else:
      text += '.'*(C-1) + 'c' 
  return '%s'%(text)

def print_case_R1orC1(R,C,N):
  
  if R==1:
    text = 'c' + '.'*(N-1) + '*'*(C-N) 
  elif C==1:
    text = 'c\n' + '.\n'*(N-1) + '*\n'*(R-N-1) + '*'
  else:
    print '\n\n ERROR in print_case_R1orC1\n\n'
    exit(0)
  return text

def print_case_N1(R,C):
  text = ''
  for r in xrange(R):
    if r != R-1:
      text += '*'*C + '\n' 
    else:
      text += '*'*(C-1) + 'c' 
  return '%s'%(text)

def print_case_N4(R,C):
  text = ''
  for r in xrange(R):
    if r < R-2:
      text += '*'*C + '\n' 
    elif r == R-2:
      text += '*'*(C-2) + '..\n' 
    else:
      text += '*'*(C-2) + '.c' 
  return '%s'%(text)

def print_case_Nx(R,C,N):
  if N%2 == 1:
    Nimpar = 1
    N = N-1
  else:
    Nimpar = 0

  matrix = [['*' for c in xrange(C)] for r in xrange(R)]
  matrix[0][0] = 'c'
  matrix[1][0] = '.'
  matrix[0][1] = '.'
  matrix[1][1] = '.'
  Np = 4
  
  rr  = 1
  cc  = 1
  dir = 0
  while (Np < N) and (cc+1<C or rr+1<R):
    if dir == 0:
      if cc+1 < C:
        matrix[0][cc+1] = '.'
        matrix[1][cc+1] = '.'
        Np += 2
      dir = 1
    else:
      if rr+1 < R:
        matrix[rr+1][0] = '.'
        matrix[rr+1][1] = '.'
        Np += 2
      dir = 0
      rr += 1
      cc += 1

  if ((R==2) or (C==2)) and (Nimpar==1):
    print '\n\n ERROR in print case Nx\n\n'
    exit(0)
  else:
    N    += Nimpar
    level = 1
    while (Np < N):
      level += 1
      for r in xrange(level, R):
        matrix[r][level] = '.'
        Np += 1
        if Np == N:
          break
      if Np < N:
        for c in xrange(level+1, C):
          matrix[level][c] = '.'
          Np += 1
          if Np == N:
            break

  text = ''
  for r in xrange(R):
    if r != 0:
      text = '%s\n'%(text)
    for c in xrange(C):
      text = '%s%s'%(text,matrix[r][c])
  
  return text

ncases = int(lines[0])
lines  = lines[1:]
for n in xrange(ncases):
  line   = lines[0].split()
  lines  = lines[1:]
  R      = int(line[0])
  C      = int(line[1])
  M      = int(line[2])

  N = R*C - M

  res = 'Impossible'

  # --- All Mines Cases -------------------
  if N <= 0:
    res = 'Impossible'

  # --- Zero Mines Cases ------------------
  elif M == 0:
    res = print_case_M0(R,C)
    
  # --- Vector Cases ----------------------
  elif (R==1) or (C==1):
    res = print_case_R1orC1(R,C,N)

  # --- Matriz Cases ----------------------
  elif N == 1:
    res = print_case_N1(R,C)
  elif N == 2:
    res = 'Impossible'
  elif N == 3:
    res = 'Impossible'
  elif N == 4:
    res = print_case_N4(R,C)
  elif N == 5:
    res = 'Impossible'
  elif N == 6: 
    res = print_case_Nx(R,C,N)
  elif N == 7:
    res = 'Impossible'
  elif N%2 == 0:               # N pares mayores o iguales a 8
    res = print_case_Nx(R,C,N)
  else:                        # N impares mayores o iguales a 9
    if ((R==2) or (C==2)):
      res = 'Impossible'
    else:
      res = print_case_Nx(R,C,N)
  
  res = 'Case #%d:\n%s'%(n+1, res)
  ofile.write('%s\n'%(res))
  print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     
