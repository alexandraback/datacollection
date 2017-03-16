from sys import stdin

T = stdin.readline() # ignored
cases = [tuple(int(y) for y in x.split()) for x in stdin.read().splitlines()]

for k, (R, C, M) in enumerate(cases, 1):
  # s'il y a une solution on peut en trouver une pour lesquelles un certain
  # nombre de lignes en bas et de colonnes à droite sont entièrement minées

  m, x, y = 0, 0, 0
  for i in range(R):
    for j in range(C):
      p = i*C + j*R - i*j
      if (i == 0 or R > i + 1) and (j == 0 or C > j + 1) and p <= M and p > m:
        m = p
        x, y = i, j

  print('Case #%d:' % k)
  R, C, M = R - x, C - y, M - m
  grid = [['.' for j in range(C)] for i in range(R)]
  grid[R-1][C-1] = 'c'
  i, j = 0, 0
  q = False
  for m in range(M):
    if not q:
      if j > C - 3:
        j = 0
        i += 1
      if j > C - 3 or i > R - 3:
        q = True
        j = max(0, C - 2)
        i = 0
    if q:
      if j == C:
        j = max(0, C - 2)
        i += 1
    grid[i][j] = '*'
    j += 1

  if q and M != R*C - 1:
    print('Impossible')
  else:
    for i in range(x):
      print('*' * (C+y))
    for i in range(R):
      print('*' * y + ''.join(grid[i]))
