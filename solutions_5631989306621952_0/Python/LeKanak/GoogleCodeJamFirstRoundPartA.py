"""

"""

def getNewWord(stringVal):
  newVal, tmpVal, isNewLetterDefined = [], [], False

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

path = r'C:\Users\HOME\Downloads\CodeJam'
fileName = 'A-small-attempt0(1).in'
inputPath = r'%s\in\%s' % (path, fileName)
outputPath = r'%s\out\%s' % (path, fileName.replace('.in', '.out'))

outputFile = open(outputPath, 'w')
inFile = open(inputPath, 'r')
inFile.next()
for i, line in enumerate(inFile):
  outputFile.write('Case #%s: %s\n' % (i + 1, getNewWord(line.strip())))
outputFile.close()