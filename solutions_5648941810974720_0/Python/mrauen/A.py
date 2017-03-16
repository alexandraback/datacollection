import os, inspect

problemName  = 'A'
# Options are 'large', 'small', and 'example'.
testCase     = 'small'
# Only relevant for small test case.
attempt      = 0

def characterDict(string):
  characters = {}
  for c in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
    characters[c] = 0
  for c in string:
    characters[c] += 1
  return characters

def hashDict(strings):
  hashes = {}
  for c in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
    hashes[c] = set()
  for s in strings:
    for c in s:
      hashes[c].add(s)
  return hashes

def getIdentifyingCharacter(baseCounts):
  for c in baseCounts:
    if len(baseCounts[c]) == 1:
      return c
  return None

def solution(string):
  counts = characterDict(string)
  values = ['ZERO', 'ONE', 'TWO', 'THREE', 'FOUR', 'FIVE', 'SIX', 'SEVEN', 'EIGHT', 'NINE']
  baseCounts = hashDict(values)

  valuesDetermined = 0
  frequencies      = [0 for _ in xrange(10)]
  while valuesDetermined < 10:
    character = getIdentifyingCharacter(baseCounts)
    if character is None:
      print ':('
    string2   = list(baseCounts[character])[0]
    num       = values.index(string2)
    frequency = counts[character] / len([c for c in string2 if c is character])
    frequencies[num] = frequency

    for c in string2:
      counts[c] -= frequencies[num]
      if string2 in baseCounts[c]:
        baseCounts[c].remove(string2)

    valuesDetermined += 1

  returnValue = ''
  for i in xrange(10):
    for _ in xrange(frequencies[i]):
      returnValue += str(i)
  return returnValue

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
    result = solution(inputfile.readline().strip())

    with open(outFile, 'a') as f:
      f.write('Case #%d: %s\n' % (case, result))
