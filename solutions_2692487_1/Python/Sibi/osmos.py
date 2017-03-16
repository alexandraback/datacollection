from math import log

def solve(mySize,sizes):
  if len(sizes) == 0:
    return 0
  
  while sizes[0] < mySize:
    mySize = mySize + sizes.pop(0)
    if len(sizes) == 0:
      return 0
  
  if sizes[0] < 2*mySize-1:
    return 1+solve(2*mySize-1,sizes)
  
  for insertions in range(1,100):
    if mySize*(2**insertions)-(2**insertions)+1 > sizes[0]:
      break
  
  #insertions = log((sizes[0]-1.0)/(mySize-1.0))/log(2.0)
  #insertions = int(insertions)
  
  if insertions >= len(sizes):
    return len(sizes)
  else:
    return min(len(sizes),insertions+solve(mySize*2**insertions-2**insertions+1,sizes))

iFile = open("A-large.in","r")
oFile = open("output.txt","w")

cases = int(iFile.readline().strip())

for i in range(cases):

  line1 = [int(a) for a in iFile.readline().strip().split()]
  mySize = line1[0]
  sizes = [int(a) for a in iFile.readline().strip().split()]
  
  sizes.sort()
  
  if mySize == 1:
    minSolution = len(sizes)
  else:
    minSolution = solve(mySize,sizes)
  
  output = str(minSolution)
  
  oFile.write("Case #"+str(i+1)+": "+output+"\n")
