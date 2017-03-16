from sys import stdin

def win(board, c):
  def check(t):
    return t == c or t == 'T'

  for i in xrange(4):
    if all(check(board[i][j]) for j in xrange(4)): return True
    if all(check(board[j][i]) for j in xrange(4)): return True
  if all(check(board[i][i]) for i in xrange(4)): return True
  if all(check(board[i][3-i]) for i in xrange(4)): return True
  return False

def full(board):
  for i in xrange(4):
    for j in xrange(4):
      if board[i][j] == '.': return False
  return True

T = int(stdin.readline())
for i in xrange(1, T+1):
  board = [stdin.readline() for j in xrange(4)]
  stdin.readline()
  print "Case #%d:" % i,
  if win(board, 'X'): print 'X won'
  elif win(board, 'O'): print 'O won'
  elif full(board): print 'Draw'
  else: print 'Game has not completed'
