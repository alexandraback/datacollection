br = open('b.in')
br = open('B-small-attempt0.in')
br = open('B-large.in')
pw = open('b-large.out', 'w')

t = int(br.readline())

def can(a, x, y, n, m):
  e, f = 1, 1
  for i in range(m):
    if a[x][i] > a[x][y]:
      e = 0
  for i in range(n):
    if a[i][y] > a[x][y]:
      f = 0
  return e | f

def solve(a, n, m):
  b = [[0 for x in range(m)] for y in range(n)]
  for i in range(n):
    for j in range(m):
      if not b[i][j]:
        b[i][j] = can(a, i, j, n, m)
  for i in range(n):
    for j in range(m):
      if not b[i][j]:
        return "NO"
  return "YES"

for i in range(1, t + 1):
  n, m = map(int, br.readline().split())
  a = [map(int, br.readline().split()) for j in range(n)]
  r = solve(a, n, m)
  #print 'Case #%d: %s' % (i, r)
  pw.write('Case #%d: %s\n' % (i, r))
