import string, math

inputFile = open('slides.in', 'r')
inputData = inputFile.read().strip()

numCases  = int(inputData.split('\n')[0])
caseData  = inputData.split('\n')

def formatAnswer(index, answer):
  return "Case #" + str(index) + ": " + str(answer)

def computeAnswer(numBuildings, numPaths):
  if 2**(numBuildings-2) < numPaths:
    return "IMPOSSIBLE"

  paths = [ ['0'] * numBuildings for i in xrange(numBuildings)]
  for i in xrange(numBuildings):
    for j in xrange(i+1, numBuildings - 1):
      paths[i][j] = '1'
  if numPaths == 2**(numBuildings -2):
    for j in xrange(numBuildings - 1):
      paths[j][-1] =  '1'
  else:
    for j in xrange(1, numBuildings):
      if (numPaths / 2**(j-1)) % 2 == 1:
        paths[j][-1] = '1'
  return "POSSIBLE\n" + string.join([string.join(row, '') for row in paths], '\n')

for case in xrange(1, numCases+1):
  numBuildings, numPaths = [int(x) for x in string.split(caseData[case], ' ')]

  answer                 = computeAnswer(numBuildings, numPaths)
  print formatAnswer(case, answer)

