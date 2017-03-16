import os, inspect

problemName  = 'B'
# Options are 'large', 'small', and 'example'.
testCase     = 'small'
# Only relevant for small test case.
attempt      = 0

def solution(rows):
  values = {}
  for row in rows:
    for value in row:
      if value not in values:
        values[value] = 0
      values[value] += 1
  oddValues = [value for value in values if values[value] % 2 == 1]
  return map(str, sorted(oddValues))

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
    rows = [map(int, inputfile.readline().split(' ')) for _ in xrange(2*N-1)]

    # Get the result here
    result = solution(rows)

    with open(outFile, 'a') as f:
      f.write('Case #%d: %s\n' % (case, ' '.join(result)))
