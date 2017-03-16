import os, inspect

problemName  = 'C'
# Options are 'large', 'small', and 'example'.
testCase     = 'small'
# Only relevant for small test case.
attempt      = 1

def getChainStartingFromChild(i, BFFs):
  firstChild        = i
  secondToLastChild = i
  lastChild         = BFFs[i]
  children          = set([firstChild, lastChild])
  while lastChild != BFFs[BFFs[lastChild]]:
    if BFFs[lastChild] in children:
      if BFFs[lastChild] == firstChild:
        if len(children) == 2:
          return (True, (children, secondToLastChild, lastChild))
        else:
          return (False, len(children))
      else:
        return (False, 0)
    secondToLastChild = lastChild
    lastChild = BFFs[lastChild]
    children.add(lastChild)
  secondToLastChild = lastChild
  lastChild = BFFs[lastChild]
  children.add(lastChild)
  return (True, (children, secondToLastChild, lastChild))

def buildUpOptimalCircle(validIndices, chainParams):
  if len(validIndices) == 0:
    return 0

  validTransitions = {}
  for i in xrange(len(validIndices)):
    index1 = validIndices[i]
    validTransitions[index1] = []
    for j in xrange(i + 1, len(validIndices)):
      index2 = validIndices[j]
      if len(chainParams[index1].intersection(chainParams[index2])) == 0:
        validTransitions[index1].append(index2)

  validTransitionsAsSets = {}
  for validIndex in validIndices:
    validTransitionsAsSets[validIndex] = set(validTransitions[validIndex])

  result          = 0
  selectedIndexes = [validIndices[0]]
  relativeIndexes = [0]
  while True:
    result = max(result, sum(len(chainParams[x]) for x in selectedIndexes))
    # Try to append another
    appendedAnother = False
    lastIndex = selectedIndexes[-1]
    for i in xrange(len(validTransitions[lastIndex])):
      success = True
      for selectedIndex in selectedIndexes:
        if validTransitions[lastIndex][i] in validTransitionsAsSets[selectedIndex]:
          continue
        success = False
        break
      if success:
        selectedIndexes.append(validTransitions[lastIndex][i])
        relativeIndexes.append(i)
        appendedAnother = True
    # Delete the last and step to another possibility
    if not appendedAnother:
      while True:
        # One element case
        if len(selectedIndexes) == 1:
          if relativeIndexes[0] == len(validIndices) - 1:
            return result
          else:
            relativeIndexes[0] = relativeIndexes[0] + 1
            selectedIndexes[0] = validIndices[relativeIndexes[0]]
            break
        # Other case
        previousRelativeIndex = relativeIndexes[-1]
        relativeIndexes.pop()
        selectedIndexes.pop()
        newLastElement = selectedIndexes[-1]
        problemFixed = False
        for x in xrange(previousRelativeIndex + 1, len(validTransitions[newLastElement])):
          problemFixed = True
          for selectedIndex in selectedIndexes:
            if validTransitions[newLastElement][x] in validTransitionsAsSets[selectedIndex]:
              continue
            problemFixed = False
            break
          if problemFixed:
            selectedIndexes.append(validTransitions[newLastElement][x])
            relativeIndexes.append(x)
            break
        if problemFixed:
          break

  return result

def solution(N, BFFs):
  partitions = {}
  result     = 0
  validIndices = []
  chainParams  = {}
  relevantChildren = {}
  for i in xrange(N):
    (retVal, params) = getChainStartingFromChild(i, BFFs)
    if retVal:
      validIndices.append(i)
      chainParams[i] = params[0]
      relevantChildren[i] = (params[1], params[2])
    else:
      result = max(result, params)
  # If two chains are compatible, add a combo chain with a new dummy index
  counter = N
  L = len(validIndices)
  for i1 in xrange(L):
    index1 = validIndices[i1]
    for i2 in xrange(i1+1, L):
      index2 = validIndices[i2]
      if relevantChildren[index1][0] == relevantChildren[index2][1] and relevantChildren[index1][1] == relevantChildren[index2][0]:
        validIndices.append(counter)
        chainParams[counter] = chainParams[index1].union(chainParams[index2])
        counter += 1
  return max(result, buildUpOptimalCircle(validIndices, chainParams))

currentDir   = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
if testCase in ['large', 'example']:
  inputString  = problemName + ('-%s' % testCase)
  outputString = problemName + ('-%s' % testCase)
else:
  inputString  = problemName + ('-%s-attempt%d' % (testCase, attempt))
  outputString = problemName + ('-%s' % testCase)

inFile       = os.path.join(currentDir, 'inputfiles', '%s.in' % inputString)
outFile      = os.path.join(currentDir, 'outputfiles', '%s.out' % outputString)

if os.path.exists(outFile):
  os.remove(outFile)

with open(inFile, 'r') as inputfile:
  numberOfCases = int(inputfile.readline())
  for case in xrange(1, numberOfCases + 1):
    N    = int(inputfile.readline())
    BFFs = map(lambda x : int(x) - 1, inputfile.readline().split(' '))
    # Get the result here
    result = solution(N, BFFs)

    with open(outFile, 'a') as f:
      f.write('Case #%d: %d\n' % (case, result))
