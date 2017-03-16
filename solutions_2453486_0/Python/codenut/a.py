br = open('a.in')
br = open('A-small-attempt0.in')
pw = open('a.out', 'w')

t = int(br.readline())

def win(bo):
  for i in range(0, 4):
    c, j = bo[i][0], 1
    if c == 'T':
      c = bo[i][1]
    while j < 4 and ((bo[i][j] == c and bo[i][j] != '.') or bo[i][j] == 'T'):
      j += 1
    if j == 4:
      return c

def wid(bo):
  c, j = bo[0][0], 1
  if c == 'T':
    c = bo[1][1]
  while j < 4 and ((bo[j][j] == c and bo[j][j] != '.') or bo[j][j] == 'T'):
    j += 1
  if j == 4:
    return c;

def wib(bo):
  c, i, j = bo[3][0], 2, 1 
  if c == 'T':
    c = bo[2][1]
  while j < 4 and ((bo[i][j] == c and bo[i][j] != '.') or bo[i][j] == 'T'):
    i -= 1 
    j += 1
  if j == 4:
    return c;

def solve(bo):
  h = win(bo)      
  if h: return h
  v = win(zip(*bo))
  if v: return v
  d = wid(bo)
  if d: return d
  e = wib(bo)
  if e: return e
  
  
for i in range(1, t + 1):
  hd, bo = 0, []
  for j in range(0, 4):
    bo.append(br.readline().strip())
    if '.' in bo[j]:
      hd = 1
  br.readline()
  r = solve(bo)
  if r:
    r = r + " won"
  if not r and not hd:
    r = "Draw"
  if not r and hd:
    r = "Game has not completed"
  print 'Case #%d: %s' % (i, r)
  pw.write('Case #%d: %s\n' % (i, r))
