from sys import stdin

def solve(a):
  for player in ['X', 'O']:
    full = True
    for row in range(4):
      won = True
      for col in range(4):
        if (a[row][col] != player and a[row][col] != 'T'):
          won = False
        if a[row][col] == '.':
          full = False
      if won:
        return player + ' won'
    for col in range(4):
      won = True
      for row in range(4):
        if (a[row][col] != player and a[row][col] != 'T'):
          won = False
      if won:
        return player + ' won'
    won = True
    for x in range(4):
      if (a[x][x] != player and a[x][x] != 'T'):
        won = False
    if won:
      return player + ' won'
    won = True
    for x in range(4):
      if (a[x][3-x] != player and a[x][3-x] != 'T'):
        won = False
    if won:
      return player + ' won'
  if full:
    return 'Draw'
  else:
    return 'Game has not completed'


n = int(stdin.readline())
for i in range(n):
  a = [[] for t in range(4)]
  for t in range(4):
    line = stdin.readline()
    for e in range(4):
      a[t].append(line[e])
  stdin.readline()
  print 'Case #' + str(i + 1) + ':', solve(a)
print

