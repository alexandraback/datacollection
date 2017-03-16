def getCorrectWord(stringVal):
  '''  '''
  newVal, tmpVal = [], []
  pivot = ord(stringVal[0])
  newVal.append(stringVal[0])
  for i in stringVal[1:]:
    tmpVal = []
    if pivot <= ord(i):
      tmpVal.append(i)
      tmpVal.extend(newVal)
      newVal = list(tmpVal)
      pivot = ord(i)
    else:
      newVal.append(i)
  return "".join(newVal)

# Path with the files
path = r'C:\CodeJam'
fileName = 'A-large.in'
inputPath = r'%s\in\%s' % (path, fileName)
outputPath = r'%s\out\%s' % (path, fileName.replace('.in', '.out'))

# Write to the file
outputFile = open(outputPath, 'w')
inFile = open(inputPath, 'r')
inFile.next()
for i, line in enumerate(inFile):
  outputFile.write('Case #%s: %s\n' % (i + 1, getCorrectWord(line.strip())))
outputFile.close()