import sys

def docase(f,k):
  dim = f.next().split()
  N = int(dim[0])
  M = int(dim[1])
  lawn = []
  for i in xrange(N):
    row = map(int,f.next().split())
    lawn.append(row)
  tlawn = []
  for j in xrange(M):
    tlawn.append([row[j] for row in lawn])
  for i in xrange(N):
    for j in xrange(M):
      elt = lawn[i][j]
      if max(lawn[i]) > elt and max(tlawn[j]) > elt:
        print "Case #" + str(k+1) + ": " + "NO"
        return
  print "Case #" + str(k+1) + ": " + "YES"

with open(sys.argv[1],"r") as f:
  T = int(f.next())
  for k in xrange(T):
    docase(f,k)