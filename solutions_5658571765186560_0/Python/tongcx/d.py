from sys import stdin

T = int(stdin.readline())

for _ in range(T):
  X, R, C = map(int, stdin.readline().split())

  if R*C % X != 0:
    ans = 'RICHARD'
  else:
    if R < C:
      R, C = C, R
    if X > R or (X + 1) / 2 > C:
      ans = 'RICHARD'
    else:
      ans = 'GABRIEL'

  print 'Case #{}: {}'.format(_+1, ans)
