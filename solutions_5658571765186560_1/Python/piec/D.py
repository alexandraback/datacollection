import sys
import string




def guess(X, R, C):
  R, C = min(R,C), max(R,C)

  if ((R*C) % X) != 0:
    return False

  if X == 1 or X == 2:
    return True

  if X == 3:
    if R == 1:
      return False
    return True

  if X == 4:
    if C < 4:
      return False
    if R == 1:
      return False
    if R == 2:
      return False
    return True

  if X >= 7:
    return False

  if X == 5:
    if C < 5:
      return False
    if R <=2:
      return False
    return True

  if X == 6:
    if C < 6:
      return False
    if R <=3:
      return False

  return True

numcases = int(sys.stdin.readline())
for casenum in range(1,numcases+1):
  params = string.split(sys.stdin.readline().strip())
  X, R, C = map(int, params)

  can = guess(X, R, C)

  if can is None:
    name = "UNKNOWN"
  elif can:
    name = "GABRIEL"
  else:
    name = "RICHARD"
  print 'Case #' + repr(casenum) + ': ' + name
