from sys import stdin

T = int(stdin.readline())

def getmin(board):
  k = min([min(r) for r in board])
  for i in xrange(len(board)):
    for j in xrange(len(board[i])):
      if board[i][j] == k: return (k, i, j)

def empty(board):
  if len(board) == 0 or len(board[0]) == 0: return True
  return False

def reduce(board):
  if empty(board): return False
  k, i, j = getmin(board)
  if all(board[i][p] == k for p in xrange(len(board[i]))):
    del board[i]
    return True
  if all(board[p][j] == k for p in xrange(len(board))):
    for p in xrange(len(board)): del board[p][j]
    return True
  return False

for t in xrange(1, T+1):
  N, M = map(int, stdin.readline().split())
  board = [map(int, stdin.readline().split()) for n in xrange(N)]
  while reduce(board): pass
  print 'Case #%d:' % t,
  if empty(board): print 'YES'
  else: print 'NO'
