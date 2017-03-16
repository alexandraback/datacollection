import os
import sys
import math

#Conditions for being feasible:
# 1/ the clicked cell is not neighor with any bomb
# 2/ no cell should be hidden behind a bomb
#
# if only 1 line or 1 column -> ok if more than 2 free cells.
# otherwise:
# put C in the top left corner
# put the next 3 free cells around it.
# then fills along the longest dimension iteratively add one free cell 

def solvePbs(pbs,pathOut):
  fout = open(pathOut,'w')
  for i in range(len(pbs[1:])):
    fout.write("Case #"+str(i+1)+":\n"+solveCase(pbs[i+1]))
  fout.close()

def getNeighborsList(field, h, l):
  neighbors = []
  for hi in range(h-1,h+2):
    if hi >= 0 and hi < len(field):
      for li in range(l-1, l+2):
        if li >= 0 and li < len(field[0]):
          if not (hi,li) == (h,l):
            neighbors.append((hi,li))
  return neighbors

def hasNeigborhingBomb(field, h, l):
  neighors = getNeighborsList(field, h, l)
  for n in neighbors:
    if field[n[0]][n[1]] == '*':
      return True
  return False

def checkOkNeighboors(field, h, l):
  neighbors = getNeighborsList(field,h,l)
  for n in neighbors:
    if not field[n[0]][n[1]] == '*':
      if not hasNeigborhingBomb(field, n[0], n[1]):
        return True
  return False

def checkFeasibility(field):
  for h in range(len(field)):
    for l in range(len(field[h])):
      if field[h][l] == '.' or field[h][l] == 'c':
        if not checkOkNeighboors(field, h, l):
          return False
  return True

def printField(field):
  s = ''
  for l in field:
    for c in l:
      s += c
    s+='\n'
  return s

def turn(field):
  turned = [[field[i][j] for i in range(len(field))] for j in range(len(field[0]))]
  return turned

def solveCase(pb):
  height = pb[0]
  length = pb[1]
  if length < height:
    length = pb[0]
    height = pb[1]
  nbMines = pb[2]
  nbFree = height*length - nbMines
  field = [ ['*' for i in range(length)] for j in range(height)]
  if nbMines == height*length - 1:
    field[0][0] = 'c'
    if pb[1] < pb[0]:
      field = turn(field)
    return printField(field)
  if nbMines > height*length - 2:
    return "Impossible\n"
  elif length == 1:
    field[0][0] = 'c'
    for i in range(1,nbFree):
      field[i][0] = '.'
    if pb[1] < pb[0]:
      field = turn(field)
    return printField(field)
  elif height == 1:
    field[0][0] = 'c'
    for i in range(1,nbFree):
      field[0][i] = '.'
    if pb[1] < pb[0]:
      field = turn(field)
    return printField(field)
  else:
    for div in range(2,1+min(length,int(math.ceil(float(nbFree)/2)))):
      rest =  nbFree % div
      sol = nbFree/div
      if (not rest == 1) and sol <= height and sol > 1 and (rest == 0 or (rest < height and div < length) or (rest < length and sol < height)):
        print height, length, div, sol, rest
        for i in range(sol):
          for j in range(div):
            field[i][j] = '.'
        if div < length and rest < height:
          for j in range(rest):
            field[j][div] = '.'
        else:
          for j in range(rest):
            field[sol][j] = '.'
        field[0][0] = 'c'
        if pb[1] < pb[0]:
          field = turn(field)
        return printField(field)
    for div in range(2,1+min(length-1,int(math.ceil(float(nbFree)/2)))):
      rest = (nbFree-2) % div 
      sol = (nbFree-2) / div
      if (not rest == 1) and sol <= height and sol > 1 and (rest == 0 or (rest < height and div < length) or (rest < length and sol < height)):

        print height, length, div, sol, rest
        for i in range(sol):
          for j in range(div):
            field[i][j] = '.'
        if div < length and rest < height:
          for j in range(rest):
            field[j][div] = '.'
          if div < length-1:
            field[0][div+1]= '.'
            field[1][div+1]= '.'
          else:
            field[sol][0] = '.'
            field[sol][1] = '.'
        else:
          for j in range(rest):
            field[sol][j] = '.'
          field[sol+1][0] = '.'
          field[sol+1][1] = '.'
        field[0][0] = 'c'
        if pb[1] < pb[0]:
          field = turn(field) 
        return printField(field)
  return 'Impossible\n'

def readIntLine(line):
  elems = line.split(' ')
  toReturn = []
  for e in elems:
    toReturn.append(int(e))
  return toReturn

def readFloatLine(line):
  elems = line.split(' ')
  toReturn = []
  for e in elems:
    toReturn.append(float(e))
  return toReturn


def breakInCases(pathIn):
  cases = []
  fin = open(pathIn,'r')
  lines = fin.readlines()
  for line in lines:
    cases.append(readIntLine(line))
  return cases 
 
def main():
  args = sys.argv[1:]
  cases = breakInCases(args[0])
  solvePbs(cases,args[1])

if __name__ == "__main__":
  main()

# vim:set encoding=utf-8 
# vim:set fileencoding=utf-8
