field = [[0]*100 for bla in range(100)]

def solve(probability,height,leftCount,rightCount,count):
  global field
  
  if count == 0:
    return
  
  leftFree = False
  rightFree = False
  
  if leftCount < 2*height:
    leftFree = True
  
  if rightCount < 2*height:
    rightFree = True
  
  if leftFree:
    if rightFree:
      field[50+leftCount-2*height][leftCount] += 0.5*probability
      field[50+2*height-rightCount][rightCount] += 0.5*probability
      solve(0.5*probability,height,leftCount+1,rightCount,count-1)
      solve(0.5*probability,height,leftCount,rightCount+1,count-1)
    else:
      field[50+leftCount-2*height][leftCount] += probability
      solve(probability,height,leftCount+1,rightCount,count-1)
  else:
    if rightFree:
      field[50+2*height-rightCount][rightCount] += probability
      solve(probability,height,leftCount,rightCount+1,count-1)
    else:
      field[50][2*height] += probability
      solve(probability,height+1,0,0,count-1)
  
iFile = open("B-small-attempt0.in","r")
oFile = open("output.txt","w")

cases = int(iFile.readline().strip())

for i in range(cases):

  line1 = [int(a) for a in iFile.readline().strip().split()]
  N = line1[0]
  X = line1[1]
  Y = line1[2]
  
  solve(1.0,0,0,0,N)
  
  if abs(X) > 45 or abs(Y) > 45:
    output = "0.0"
  else:
    output = str(field[50+X][Y])
  
  field = [[0]*100 for bla in range(100)]
  
  
  oFile.write("Case #"+str(i+1)+": "+output+"\n")
