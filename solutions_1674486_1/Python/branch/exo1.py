import os
import sys

def solveCase(aCase):
  inheritanceGraph = []
  for i in range(1,len(aCase)):
    inheritanceGraph.append([])
    elem = aCase[i].split()
    for j in range(1,len(elem)):
      inheritanceGraph[i-1].append(int(elem[j])-1)
  for i in range(len(inheritanceGraph)):
    if isIDiamond(i,inheritanceGraph):
      return True
  return False

def isIDiamond(i,inheritanceGraph):
  visited = []
  for j in range(len(inheritanceGraph)):
    visited.append(False)
  toPropagate = []
  for el in inheritanceGraph[i]:
    toPropagate.append(el)
  while len(toPropagate) > 0:
    toP = toPropagate[0]
    toPropagate.pop(0)
    if visited[toP]:
      return True
    else:
      visited[toP] = True
      for el in inheritanceGraph[toP]:
        toPropagate.append(el)
  return False

def solve(pathI,pathOut):
  counter = 1
  fI = file(pathI,'rU')
  fO = file(pathOut,'w')
  lines = fI.readlines()
  nbCases = int(lines[0])
  line = 1
  for case in range(nbCases):
    endLine = int(lines[line]) + line + 1
    ok = solveCase(lines[line:endLine])
    line = endLine
    fO.write('Case #')
    fO.write(str(counter))
    fO.write(': ')
    if ok:
      fO.write('Yes')
    else:
      fO.write('No')
    fO.write('\n')
    counter+=1
  fI.close()
  fO.close()



def main():
  args = sys.argv[1:]
  solve(args[0],args[1])


main()

