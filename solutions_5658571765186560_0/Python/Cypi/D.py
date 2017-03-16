def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

_T = readint()
for _t in range(_T):

  X, R, C = readarray(int)
  if R > C:
    R, C = C, R
  # R <= C
  if X >= 7:
    res = 'RICHARD'
  elif C < X:
    res = 'RICHARD'
  elif (R*C)%X != 0:
    res = 'RICHARD'
  elif X <= 2:
    res = 'GABRIEL'
  elif X == 3:
    if R < 2:
      res = 'RICHARD'
    else:
      # At least 2x3
      res = 'GABRIEL'
  elif X == 4:
    if R < 3:
      res = 'RICHARD'
    else:
      # At least 3x4
      res = 'GABRIEL'
  elif X == 5:
    if R < 3:
      res = 'RICHARD'
    else:
      # At least 3x5
      if R == 3 and C == 5:
        res = 'RICHARD'
      else:
        res = 'GABRIEL'
  elif X == 6:
    if R < 3:
      res = 'RICHARD'
    else:
      # At least 3x6
      res = 'toto'


  print 'Case #%i:'%(_t+1), res
