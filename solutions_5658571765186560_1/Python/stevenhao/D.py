def solve():
  X, R, C = [int(_) for _ in raw_input().split()]
  R, C = max(R, C), min(R, C)
  if R * C % X != 0:
    return False
  if X >= 7:
    return False
  if R < X:
    return False

  if X <= 2:
    return True
  elif X == 3:
    return C >= 2
  elif X == 4:
    if C <= 2:
      return False
    else:
      return True
  elif X == 5:
    if C <= 2:
      return False
    elif C == 3 and R == 5:
      return False
    else:
      return True
  elif X == 6:
    if C <= 3:
      return False
    else:
      return True

T = input()
for t in range(1, T + 1):
  print 'Case #%d: %s' % (t, 'GABRIEL' if solve() else 'RICHARD')
