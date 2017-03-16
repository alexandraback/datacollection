"""

"""

import collections

def getOddsValOrdered(countNums):
  """
  """
  res = []
  for val, countVal in countNums.iteritems():
    if countVal % 2 == 1:
      res.append(int(val))
  return " ".join(map(lambda x: str(x), sorted(res)))

path = r'C:\Users\HOME\Downloads\CodeJam'
fileName = 'B-small-attempt1.in'
inputPath = r'%s\in\%s' % (path, fileName)
outputPath = r'%s\out\%s' % (path, fileName.replace('.in', '.out'))

outputFile = open(outputPath, 'w')
inFile = open(inputPath, 'r')
inFile.next()
colsNumber = int(inFile.next().strip())
countNums, testCase = collections.defaultdict(int), 1
for i, line in enumerate(inFile):
  colsData = line.strip().split(" ")
  if len(colsData) == 1:
    outputFile.write('Case #%s: %s\n' % (testCase, getOddsValOrdered(countNums)))
    countNums = collections.defaultdict(int)
    testCase += 1
    continue

  for val in colsData:
    countNums[val] += 1

outputFile.write('Case #%s: %s\n' % (testCase, getOddsValOrdered(countNums)))
outputFile.close()


