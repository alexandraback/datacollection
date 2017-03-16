import collections

def getOrderedRes(Nums):
  ''' '''
  res = []
  for val, countVal in Nums.iteritems():
    if countVal % 2 == 1:
      res.append(int(val))
  return " ".join(map(lambda x: str(x), sorted(res)))

  
# Path with the files
path = r'C:\CodeJam'
fileName = 'B-large.in'
inputPath = r'%s\%s' % (path, fileName)
outputPath = r'%s\%s' % (path, fileName.replace('.in', '.out'))

# Write to the file
outputFile = open(outputPath, 'w')
inFile = open(inputPath, 'r')
inFile.next()
colsNumber = int(inFile.next().strip())
countNums, testCase = collections.defaultdict(int), 1
for i, line in enumerate(inFile):
  colsData = line.strip().split(" ")
  if len(colsData) == 1:
    outputFile.write('Case #%s: %s\n' % (testCase, getOrderedRes(countNums)))
    countNums = collections.defaultdict(int)
    testCase += 1
    continue

  for val in colsData:
    countNums[val] += 1

outputFile.write('Case #%s: %s\n' % (testCase, getOrderedRes(countNums)))
outputFile.close()


