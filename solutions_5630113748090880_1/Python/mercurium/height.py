import string

inputFile  = open('height.in', 'r')
inputData  = inputFile.read().strip()

numCases   = int(inputData.split('\n')[0])
heightData = inputData.split('\n')

def formatAnswer(index, answer):
  answer = string.join([str(x) for x in answer], ' ')
  return "Case #" + str(index) + ": " + answer

def computeAnswer(heights):
  heights.sort()
  heightCount = dict()
  for row in heights:
    for i in row:
      if i in heightCount:
        heightCount[i] += 1
      else:
        heightCount[i] = 1

  oddCounts = []
  for key in sorted(heightCount.keys()):
    if heightCount[key] % 2 == 1:
      oddCounts.append(key)
  return sorted(oddCounts)

index = 1
for case in xrange(1,numCases +1):
  numRow = int(heightData[index])
  heights = [ [int(x) for x in row.split(' ')] \
              for row in heightData[index + 1:index + 2*numRow] ]
  index += 2* numRow

  answer = computeAnswer(heights)
  print formatAnswer(case, answer)


