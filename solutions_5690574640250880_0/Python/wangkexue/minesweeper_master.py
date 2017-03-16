import sys
from copy import deepcopy

def solve(r, c, m):
  #board = [['*' for x in range(c)] for y in range(r)]
  # visited mask
  #mask = 
  if r*c - m == 1:
    board = [['*' for x in range(c)] for y in range(r)]
    board[0][0] = 'c'
    print '\n'.join([''.join(x) for x in board])
    return
  for i in range(r):
    for j in range(c):
      if check(i, j, r, c, r*c-m, [['*' for x in range(c)] for y in range(r)], [[0 for x in range(c)] for y in range(r)]):
        return
  print 'Impossible'

def check(i, j, r, c, m, board, mask):
  board[i][j] = 'c'
  m -= 1
  mask[i][j] = 1
  m , board = set_val(i, j, r, c, m, board)
  #print m
  if m < 0:
    return False
  if m > 0:
    return expand(i-1,j,r,c,m,deepcopy(board), deepcopy(mask)) or expand(i,j-1,r,c,m,deepcopy(board), deepcopy(mask)) or expand(i+1,j,r,c,m,deepcopy(board), deepcopy(mask)) or expand(i,j+1,r,c,m,deepcopy(board), deepcopy(mask)) or expand(i-1,j-1,r,c,m,deepcopy(board), deepcopy(mask)) or expand(i+1,j+1,r,c,m,deepcopy(board), deepcopy(mask)) or expand(i-1,j+1,r,c,m,deepcopy(board), deepcopy(mask)) or expand(i+1,j-1,r,c,m,deepcopy(board), deepcopy(mask))
  if m == 0:
    board = [''.join(x) for x in board]
    print '\n'.join(board)
    return True

def expand(i, j, r, c, m, board, mask):
  if i < 0 or j < 0 or i >= r or j >= c:
    return False
  if mask[i][j] == 1:
    return False
  #print str(i)+' '+str(j)
  mask[i][j] = 1
  #maskc = deepcopy(mask)
  #print 'm(expand): ' + str(m)
  m, board = set_val(i, j, r, c, m, board)
  #print m
  if m < 0:
    #print 'YES'
    #print '\n'.join([''.join(x) for x in board])

    return False
  if m > 0:
    #print '\n'.join([''.join(x) for x in board])

    return expand(i-1,j,r,c,m,deepcopy(board), deepcopy(mask)) or expand(i,j-1,r,c,m,deepcopy(board), deepcopy(mask)) or expand(i+1,j,r,c,m,deepcopy(board), deepcopy(mask)) or expand(i,j+1,r,c,m,deepcopy(board), deepcopy(mask)) or expand(i-1,j-1,r,c,m,deepcopy(board), deepcopy(mask)) or expand(i+1,j+1,r,c,m,deepcopy(board), deepcopy(mask)) or expand(i-1,j+1,r,c,m,deepcopy(board), deepcopy(mask)) or expand(i+1,j-1,r,c,m,deepcopy(board), deepcopy(mask))
  if m == 0:
    board = [''.join(x) for x in board]
    print '\n'.join(board)
    return True

def set_val(i, j, r, c, m, board):
  #print 'm: ' + str(m)
  if i > 0:
    if board[i-1][j] == '*':
      board[i-1][j] = '.'
      m -= 1
  if j > 0:
    if board[i][j-1] == '*':
      board[i][j-1] = '.'
      m -= 1
  if r - i - 1 > 0:
    if board[i+1][j] == '*':
      board[i+1][j] = '.'
      m -= 1
  if c - j - 1 > 0:
    if board[i][j+1] == '*':
      board[i][j+1] = '.'
      m -= 1
  if i > 0 and j > 0:
    if board[i-1][j-1] == '*':
      board[i-1][j-1] = '.'
      m -= 1
  if r - i - 1 > 0 and c - j - 1 > 0:
    if board[i+1][j+1] == '*':
      board[i+1][j+1] = '.'
      m -= 1
  if i > 0 and c - j - 1 > 0:
    if board[i-1][j+1] == '*':
      board[i-1][j+1] = '.'
      m -= 1
  if r - i - 1 > 0 and j > 0:
    if board[i+1][j-1] == '*':
      board[i+1][j-1] = '.'
      m -= 1
  return m, board

numcases = int(sys.stdin.readline())
for casenum in range(1,numcases+1):
    r, c, m = [int(x) for x in sys.stdin.readline().split()]
    print 'Case #' + repr(casenum) + ':'
    solve(r,c,m)