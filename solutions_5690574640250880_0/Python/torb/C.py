from sys import stdin
from collections import deque

def generate(R, C, B):
  m = [['*'] * C for i in xrange(R)]
  count = 0
  F = R * C - B
  q = deque()
  q.append((0, 0))
  while count < F:
    ds = [(0, 1), (1, 0), (1, 1)]
    x, y = q.popleft()
    if x >= R or y >= C or m[x][y] == 'x':
      continue
    count += 1
    m[x][y] = 'x'
    for xa, ya in ds:
      q.append((x+xa, y+ya))


  c1 = 0
  r1 = 0
  for i in xrange(R-1, -1, -1):
    if m[i][0] == 'x':
      r1 = i
      for j in xrange(C):
        if m[i][j] == 'x':
          c1 += 1
      break

  c2 = 0
  r2 = 0
  for i in xrange(C-1, -1, -1):
    if m[0][i] == 'x':
      r2 = i
      for j in xrange(R):
        if m[j][i] == 'x':
          c2 += 1
      break
  
  if c1 > 2 and c2 == 1 and R != 1:
    m[r1][c1-1] = "*"
    m[c2][r2] = 'x'
  if c2 > 2 and c1 == 1 and C != 1:
    m[r1][c1] = "x"
    m[c2-1][r2] = '*'

  q = deque()
  q.append((0, 0))
  while q:
    (x, y) = q.popleft()
    if m[x][y] == '.':
      continue

    dx = [-1, -1, -1, 0, 0, 1, 1, 1]
    dy = [1, 0, -1, -1, 1, -1, 0, 1]
    
    a = True
    for i in xrange(8):
      nx = x + dx[i]
      ny = y + dy[i]
      if nx < 0 or nx >= R or ny < 0  or ny >= C:
        continue
      if m[nx][ny] != 'x' and m[nx][ny] != '.':
        a = False

    if a:
      for i in xrange(8):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx >= R or ny < 0  or ny >= C:
          continue
        q.append([nx, ny])

    m[x][y] = '.'
    
  m[0][0] = 'c'


  for line in m:
    for cell in line:
      if cell == 'x':
        return "Impossible"

  result = "\n".join(["".join(line) for line in m])
  return result

TC = int(stdin.readline())
for tc in xrange(1, TC+1):
  R, C, M = (int(x) for x in stdin.readline().split())
  print "Case #%d:\n%s" % (tc, generate(R, C, M))
