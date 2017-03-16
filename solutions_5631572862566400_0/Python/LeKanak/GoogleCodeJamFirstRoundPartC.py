"""

"""

import collections


def getMaxRaw(raw):

  children = map(lambda x: int(x), raw)
  friends = collections.defaultdict(set)
  for i, friend in enumerate(children):
    friends[i+1].add(friend)
    friends[friend].add(i+1)


  longestRaw, res, ordRaw = {}, [], []
  for i in range(1, len(children)+1):
    lastChild = i
    longestRaw = {i: i}
    ordRaw = [i]
    while True:

      for newChild in friends[lastChild]:
        if not newChild in longestRaw:
          longestRaw[newChild] = newChild
          ordRaw.append(newChild)
          lastChild = newChild
          break

      else:
        break

    if len(longestRaw) > len(res):
      res = list(longestRaw.keys())

  while ordRaw[-1] not in friends[ordRaw[0]]:
    del ordRaw[-1]

  return len(ordRaw)

path = r'C:\Users\HOME\Downloads\CodeJam'
fileName = 'C-small-attempt2.in'
inputPath = r'%s\in\%s' % (path, fileName)
outputPath = r'%s\out\%s' % (path, fileName.replace('.in', '.out2'))

outputFile = open(outputPath, 'w')
inFile = open(inputPath, 'r')
inFile.next()
testCase = 0
for i, line in enumerate(inFile):
  colsData = line.strip().split(" ")
  if len(colsData) == 1:
    testCase += 1
    continue

  outputFile.write('Case #%s: %s\n' % (testCase, getMaxRaw(colsData)))

outputFile.close()