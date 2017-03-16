import os, inspect

problemName  = 'A'
# Options are 'large', 'small', and 'example'.
testCase     = 'large'
# Only relevant for small test case.
attempt      = 0

def solution(string):
  maximumLettersAndIndices = []
  characterInts  = map(ord, string)
  currentMaximum      = -1
  currentMaximumIndex = -1
  for index in xrange(len(string)):
    char = characterInts[index]
    if char >= currentMaximum:
      currentMaximum = char
      currentMaximumIndex = index
    maximumLettersAndIndices.append((currentMaximum, currentMaximumIndex))
  prefixArray  = []
  suffixArray  = []
  currentIndex = len(string) - 1
  while currentIndex >= 0:
    (maximumLetter, maximumIndex) = maximumLettersAndIndices[currentIndex]
    prefixArray.append(maximumLetter)
    suffixArray = characterInts[maximumIndex + 1 : currentIndex + 1] + suffixArray
    currentIndex = maximumIndex - 1
  return ''.join(map(chr, prefixArray + suffixArray))

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
    string = inputfile.readline().strip()

    # Get the result here
    result = solution(string)

    with open(outFile, 'a') as f:
      f.write('Case #%d: %s\n' % (case, result))
