import string

inputFile = open('fashion_police.in', 'r')
inputData = inputFile.read().strip()

numCases  = int(inputData.split('\n')[0])
caseData  = inputData.split('\n')

def formatAnswer(index, answer):
  return "Case #" + str(index) + ": " + str(answer)

def formatDay(day):
  return string.join([str(x) for x in day], ' ')

precomputed = [(1,1,1), (1,1,3), (1,2,1), (1,2,2), (1,3,2), (1,3,3), \
    (2,1,1), (2,1,2), (2,2,2), (2,2,3), (2,3,1), (2,3,3), \
    (3,1,2), (3,1,3), (3,2,1), (3,2,3), (3,3,1), (3,3,2)]

def generateNthTuple(numJackets, numPants, numShirts, nthItem, limit):
  randArr    = [1,2,1,3,2,3]
  maxOnLayer = numPants * limit
  shirtItem  = (nthItem / limit) % numShirts
  pantsItem  = randArr[ nthItem % len(randArr)]
  jacketItem = nthItem % maxOnLayer + 1
  return (jacketItem, pantsItem, shirtItem) # TODO fix order of this

def computeAnswer(numJackets, numPants, numShirts, comboLimit):
  upperLim = numJackets * numPants * min(comboLimit,numShirts)
  days = [(1,1,1)]
  for day in xrange(1, upperLim):
    days.append(generateNthTuple(numJackets, numPants, numShirts, day, comboLimit))

  return str(upperLim) + "\n" + string.join([formatDay(day) for day in days], '\n')

for case in xrange(1, numCases+1):
  numJackets, numPants, numShirts, comboLimit = [int(x) for x in string.split(caseData[case], ' ')]
  answer                                      = computeAnswer(numJackets, numPants, numShirts, comboLimit)
  print formatAnswer(case, answer)

