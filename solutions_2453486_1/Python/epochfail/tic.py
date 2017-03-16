def test(f):
  if f['T'] + f['O'] == 4:
    return 'O won'
  if f['T'] + f['X'] == 4:
    return 'X won'

def work():
  grid = []
  while len(grid) < 4:
    ln = raw_input().strip()
    if len(ln) != 0:
      grid.append(ln)

  dots = False

  # Diag
  f = {'X': 0, 'O': 0, 'T': 0, '.': 0}
  for i in xrange(4):
    f[grid[i][i]] += 1
    dots = dots or grid[i][i] == '.'
  res = test(f)
  if res: return res

  f = {'X': 0, 'O': 0, 'T': 0, '.': 0}
  for i in xrange(4):
    f[grid[i][3-i]] += 1
    dots = dots or grid[i][i] == '.'
  res = test(f)
  if res: return res

  # Lines
  for x in xrange(4):
    f = {'X': 0, 'O': 0, 'T': 0, '.': 0}
    for y in xrange(4):
      f[grid[y][x]] += 1
      dots = dots or grid[y][x] == '.'
    res = test(f)
    if res: return res
  for y in xrange(4):
    f = {'X': 0, 'O': 0, 'T': 0, '.': 0}
    for x in xrange(4):
      f[grid[y][x]] += 1
      dots = dots or grid[y][x] == '.'
    res = test(f)
    if res: return res

  if dots:
    return 'Game has not completed'
  else:
    return 'Draw'

T = int(raw_input())
for _ in xrange(T):
  print 'Case #%d:' % (_+1), work()
