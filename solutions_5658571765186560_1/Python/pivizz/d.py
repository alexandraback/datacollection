import sys

def solve(X, R, C):
  if R*C % X != 0: return False
  if X >= 7: return False
  if X == 1: return True
  if X == 2: return True
  if R < (2 if X <= 4 else 3): return False
  if X == 3: return True
  if X == 4: return R > 2
  if X == 5: return True
  # X == 6
  return R > 3

for caseIndex, case in enumerate(list(sys.stdin)[1:]):
  X, R, C = list(map(int, case.rstrip().split(' ')))
  R, C = min(R, C), max(R, C)
  answer = solve(X, R, C)
  print('Case #{0}: {1}'.format(caseIndex+1, 'GABRIEL' if answer else 'RICHARD'))
