import sys, math

def readInput(fileName):
  global inputData

  inputFile = open(fileName)

  inputFile.readline() # number of test cases
  for line in inputFile:
    line = line.strip()
    if line and len(line) > 0:
      yield [int(v) for v in line.split(' ')]
      
      
def pointToFirstHit(c,w):
  return int(math.floor(float(c)/w))
  
def pointFromFirstHitToFinish(c,w):
  if c%w > 0:
    return w
  else:
    return w-1
      
i = 0
for r,c,w in readInput(sys.argv[1]):
  i += 1
  p1 = pointToFirstHit(c,w) * r
  p2 = pointFromFirstHitToFinish(c,w)
  #print "{0}x{1}: {2}".format(r,c,w)
  print "Case #{0}: {1}".format(i, p1 + p2)
      