#!/usr/bin/env python

def run(C, J, l, L):
  if l == L:
    return [''], ['']

  tempC, tempJ = run(C, J, l+1, L)

  '''
  if C[l] == '?' and J[l] == '?':
    possibleC = ['0'+x for x in tempC] + ['9'+x for x in tempC]
    possibleJ = ['0'+x for x in tempJ] + ['9'+x for x in tempJ]
  elif C[l] == '?':
    possibleC = ['0'+x for x in tempC] + ['9'+x for x in tempC]
    possibleJ = [J[l]+x for x in tempJ]
    if J[l] != '0' and J[l] != '9':
      possibleC += [J[l]+x for x in tempC]
    if int(J[l]) < 8:
      possibleC += [str(int(J[l])+1)+x for x in tempC]
    if int(J[l]) > 1:
      possibleC += [str(int(J[l])-1)+x for x in tempC]
  elif J[l] == '?':
    possibleC = [C[l]+x for x in tempC]
    possibleJ = ['0'+x for x in tempJ] + ['9'+x for x in tempJ]
    if C[l] != '0' and C[l] != '9':
      possibleJ += [C[l]+x for x in tempJ]
    if int(C[l]) < 8:
      possibleJ += [str(int(C[l])+1)+x for x in tempJ]
    if int(C[l]) > 1:
      possibleJ += [str(int(C[l])-1)+x for x in tempJ]
  else:
    possibleC, possibleJ = [C[l]+x for x in tempC], [J[l]+x for x in tempJ]
  '''
  if C[l] == '?':
    possibleC = []
    for i in xrange(10):
      possibleC += [str(i)+x for x in tempC]
  else:
    possibleC = [C[l]+x for x in tempC]

  if J[l] == '?':
    possibleJ = []
    for i in xrange(10):
      possibleJ += [str(i)+x for x in tempJ]
  else:
    possibleJ = [J[l]+x for x in tempJ]

  return possibleC, possibleJ


for nnn in xrange(1, int(raw_input())+1):
  print "Case #%d:" % (nnn),
  C, J = raw_input().strip().split()
  L = len(C)
  possibleC, possibleJ = run(C, J, 0, L)
  minimum, c, j = int('9'*L)+1, 0, 0
  for x in possibleC:
    ix = int(x)
    for y in possibleJ:
      iy = int(y)
      if abs(ix-iy) < minimum:
        minimum, c, j = abs(ix-iy), ix, iy
      elif abs(ix-iy) == minimum:
        if ix < c or (ix == c and iy < j):
          c, j = ix, iy

  print str(c).zfill(L), str(j).zfill(L)

