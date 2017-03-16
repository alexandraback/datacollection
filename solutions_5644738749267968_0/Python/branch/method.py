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
  for i in range(len(pbs)):
    fout.write("Case #"+str(i+1)+": "+solveCase(pbs[i])+'\n')
  fout.close()

def resWar(n, k):
  naomi = n[:]
  ken = k[:]
  score = 0
  indexKH = len(ken)-1
  for i in range(len(ken)):
    if naomi[len(naomi)-1-i] > ken[indexKH]:
      score += 1
    else:
      indexKH -= 1
  return score

def resDeceitfulWar(n,k): 
  naomi = n[:]
  ken = k[:]
  score = len(ken)
  i = 0
  while i < len(k) and naomi[0] < ken[0]:
    i += 1
    ken.pop(len(ken)-1)
    naomi.pop(0)
    score -= 1 
  i = len(ken) - 1
  while i >= 0 and ken[-1] > naomi[-1]:
    score -= 1
    i -= 1
    ken.pop(len(ken)-1)
    naomi.pop(0)
  while len(ken) > 0:
    if naomi[-1] > ken[-1]:
      j = 0
      while naomi[j] < ken[0]:
        j += 1
      naomi.pop(j)
      ken.pop(0)
    else:
      score -= 1
      naomi.pop(0)
      ken.pop(-1)
  return score


def solveCase(pb):
  n = pb[0]
  n.sort()
  k = pb[1]
  k.sort()
  return str(resDeceitfulWar(n,k))+' '+str(resWar(n,k))

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
  for i in range((len(lines)-1)/3):
    cases.append((readFloatLine(lines[3*i+2]),readFloatLine(lines[3*i+3])))
  return cases 
 
def main():
  args = sys.argv[1:]
  cases = breakInCases(args[0])
  solvePbs(cases,args[1])

if __name__ == "__main__":
  main()

# vim:set encoding=utf-8 
# vim:set fileencoding=utf-8
