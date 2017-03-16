import sys

from collections import defaultdict
def doTest(rowCols):
  d = defaultdict(int)
  rowSize = len(rowCols[0])
  for i in range(len(rowCols)):
    for j in range(len(rowCols[i])):
      d[rowCols[i][j]] += 1

  outList = []
  for k,v in d.items():
    if v % 2 != 0:
      outList.append(k)
  outList.sort()
  return " ".join([str(x) for x in outList])

inlines = open(sys.argv[1]).readlines()
numcases = int(inlines[0])
idx = 1

for case in range(numcases):
    N=int(inlines[idx])
    grid = []
    for i in range(2*N-1):
      grid.append(map(int, inlines[idx+1+i].split()))
    print "Case #%d: %s" % (case + 1, doTest(grid))
    idx += (2*N)


