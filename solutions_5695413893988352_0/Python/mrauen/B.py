import os, inspect

problemName  = 'B'
# Options are 'large', 'small', and 'example'.
testCase     = 'small'
# Only relevant for small test case.
attempt      = 0

def maximize(string):
  return string.replace('?', '9')

def minimize(string):
  return string.replace('?', '0')

def testCompatible(left, right):
  returnValue = ''
  L = len(left)
  for index in xrange(L):
    if left[index] == '?' and right[index] == '?':
      returnValue += '0'
    elif left[index] == '?':
      returnValue += right[index]
    elif right[index] == '?':
      returnValue += left[index]
    elif left[index] == right[index]:
      returnValue += left[index]
    else:
      return None
  return returnValue

def solution(left, right):
  L = len(left)
  returnValue = testCompatible(left, right)
  if returnValue is not None:
    return returnValue + ' ' + returnValue

  bestSum        = 0
  bestDifference = 10**20
  bestLeft       = ''
  bestRight      = ''
  prefix         = ''
  for index in xrange(L):
    if left[index] == '?' and right[index] == '?':

      possibleLeft  = prefix + '1' + minimize(left[index+1:])
      possibleRight = prefix + '0' + maximize(right[index+1:])
      possibleSum   = int(possibleLeft) + int(possibleRight)
      possibleDiff  = int(possibleLeft) - int(possibleRight)
      if bestDifference > possibleDiff or (bestDifference >= possibleDiff and bestSum > possibleSum):
        bestLeft  = possibleLeft
        bestRight = possibleRight
        bestDifference = possibleDiff
        bestSum = possibleSum

      possibleLeft  = prefix + '0' + maximize(left[index+1:])
      possibleRight = prefix + '1' + minimize(right[index+1:])
      possibleSum   = int(possibleLeft) + int(possibleRight)
      possibleDiff  = int(possibleRight) - int(possibleLeft)
      if bestDifference > possibleDiff or (bestDifference >= possibleDiff and bestSum > possibleSum):
        bestLeft  = possibleLeft
        bestRight = possibleRight
        bestDifference = possibleDiff
        bestSum = possibleSum

      prefix += '0'

    elif left[index] == '?':

      if right[index] != '9':
        possibleLeft  = prefix + str(int(right[index]) + 1) + minimize(left[index+1:])
        possibleRight = prefix + right[index] + maximize(right[index+1:])
        possibleSum   = int(possibleLeft) + int(possibleRight)
        possibleDiff  = int(possibleLeft) - int(possibleRight)
        if bestDifference > possibleDiff or (bestDifference >= possibleDiff and bestSum > possibleSum):
          bestLeft  = possibleLeft
          bestRight = possibleRight
          bestDifference = possibleDiff
          bestSum = possibleSum

      if right[index] != '0':
        possibleLeft  = prefix + str(int(right[index]) - 1) + maximize(left[index+1:])
        possibleRight = prefix + right[index] + minimize(right[index+1:])
        possibleSum   = int(possibleLeft) + int(possibleRight)
        possibleDiff  = int(possibleRight) - int(possibleLeft)
        if bestDifference > possibleDiff or (bestDifference >= possibleDiff and bestSum > possibleSum):
          bestLeft  = possibleLeft
          bestRight = possibleRight
          bestDifference = possibleDiff
          bestSum = possibleSum

      prefix += right[index]

    elif right[index] == '?':

      if left[index] != '0':
        possibleLeft  = prefix + left[index] + minimize(left[index+1:])
        possibleRight = prefix + str(int(left[index]) - 1) + maximize(right[index+1:])
        possibleSum   = int(possibleLeft) + int(possibleRight)
        possibleDiff  = int(possibleLeft) - int(possibleRight)
        if bestDifference > possibleDiff or (bestDifference >= possibleDiff and bestSum > possibleSum):
          bestLeft  = possibleLeft
          bestRight = possibleRight
          bestDifference = possibleDiff
          bestSum = possibleSum

      if left[index] != '9':
        possibleLeft  = prefix + left[index] + maximize(left[index+1:])
        possibleRight = prefix + str(int(left[index]) + 1) + minimize(right[index+1:])
        possibleSum   = int(possibleLeft) + int(possibleRight)
        possibleDiff  = int(possibleRight) - int(possibleLeft)
        if bestDifference > possibleDiff or (bestDifference >= possibleDiff and bestSum > possibleSum):
          bestLeft  = possibleLeft
          bestRight = possibleRight
          bestDifference = possibleDiff
          bestSum = possibleSum

      prefix += left[index]

    else:

      if left[index] == right[index]:
        prefix += left[index]
      elif int(left[index]) > int(right[index]):
        possibleLeft  = prefix + left[index] + minimize(left[index+1:])
        possibleRight = prefix + right[index] + maximize(right[index+1:])
        possibleSum   = int(possibleLeft) + int(possibleRight)
        possibleDiff  = abs(int(possibleRight) - int(possibleLeft))
        if bestDifference > possibleDiff or (bestDifference >= possibleDiff and bestSum > possibleSum):
          bestLeft  = possibleLeft
          bestRight = possibleRight
          bestDifference = possibleDiff
          bestSum = possibleSum
        return bestLeft + ' ' + bestRight
      else:
        possibleLeft  = prefix + left[index] + maximize(left[index+1:])
        possibleRight = prefix + right[index] + minimize(right[index+1:])
        possibleSum   = int(possibleLeft) + int(possibleRight)
        possibleDiff  = abs(int(possibleRight) - int(possibleLeft))
        if bestDifference > possibleDiff or (bestDifference >= possibleDiff and bestSum > possibleSum):
          bestLeft  = possibleLeft
          bestRight = possibleRight
          bestDifference = possibleDiff
          bestSum = possibleSum
        return bestLeft + ' ' + bestRight

  return bestLeft + ' ' + bestRight

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

    # Get the result here
    [left, right] = inputfile.readline().strip().split(' ')
    result = solution(left, right)

    with open(outFile, 'a') as f:
      f.write('Case #%d: %s\n' % (case, result))
