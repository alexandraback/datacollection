import string

inputFile = open('bff.in', 'r')
inputData = inputFile.read().strip()

numCases  = int(inputData.split('\n')[0])
cases     = inputData.split('\n')

def formatAnswer(index, answer):
  return "Case #" + str(index) + ": " + str(answer)

def computeAnswer(bffList):
  bffChainDict = dict()
  kidInCycle   = [False] * len(bffList)
  cycleLen     = [0] * len(bffList)
  entryKids    = [-1] * len(bffList)


  def cleanUp(kid):
    seenAgain  = set()
    cycleCount = 0
    while kid not in seenAgain:
      cycleCount += 1
      seenAgain.add(kid)
      kid = bffList[kid]
    while kid not in bffChainDict:
      bffChainDict[kid] = cycleCount
      kid               = bffList[kid]
      kidInCycle[kid]   = True
      cycleLen[kid]     = cycleCount
      entryKids[kid]    = kid
    return bffChainDict[kid]


  seenBefore = set()
  def getBffChain(kid):
    seenBefore.add(kid)
    if kid in bffChainDict:
      return (bffChainDict[kid], entryKids[kid])

    if bffList[kid] in seenBefore:
      prevChain = cleanUp(kid)
      if kid in bffChainDict:
        return (bffChainDict[kid], kid)

    [prevChain, entryKid] = getBffChain(bffList[kid])

    # if they were added in the clean up step
    if kid in bffChainDict:
      return (bffChainDict[kid], kid)
    else:
      bffChainDict[kid] = prevChain + 1
      entryKids[kid]    = entryKids[bffList[kid]]
      return bffChainDict[kid], entryKid

  for kid in xrange(len(bffList)):
    getBffChain(kid)

  maxLenCycle = max([(bffChainDict[kid] if kidInCycle[kid] else 0) \
      for kid in bffChainDict.keys()])

  possibleEntryPoints = []

  for kidIndex in xrange(len(bffList)):
    if cycleLen[kidIndex] == 2:
      possibleEntryPoints.append(kidIndex)


  maxPossibleChain = 0
  chainLens        = dict()
  for x in range(len(bffList)):
    chainLens[x] = 0
  for kidIndex in xrange(len(bffList)):
    entryPoint = entryKids[kidIndex]
    if entryKids[kidIndex] in chainLens:
      chainLens[entryPoint] = max(chainLens[entryPoint], bffChainDict[kidIndex])

  for entryPoint in possibleEntryPoints:
    otherPoint = bffList[entryPoint]
    maxPossibleChain = max( maxPossibleChain, \
      chainLens[entryPoint] + chainLens[otherPoint] - 2)

  return max(maxPossibleChain, maxLenCycle)


for case in xrange(1, numCases+1):
  numKids = int(cases[case*2 -1])
  kids    = [ int(kid)-1 for kid in string.split(cases[case*2], ' ')]

  answer = computeAnswer(kids)
  print formatAnswer(case, answer)


