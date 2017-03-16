import sys
from IPython.core.debugger import Tracer;

def printboard(board):
  for i in board:
    print i

def fillboard(board, topleft, mines_left, rowrem, colrem):
  col = len(board[0])
  row = len(board)
  if min(rowrem, colrem) == 2 and mines_left >0:
    return False
  if rowrem == 1 or colrem == 1:
    return False
  else:
    reduct = max(rowrem, colrem)
    if reduct == colrem:
      tmp = min(col-2,mines_left+topleft[1])
      board[topleft[0]] = ['*']  * tmp + ['.'] * (col-tmp)
      mines_left -= tmp - topleft[1]
      # Tracer()()
      if mines_left > 0:
        if topleft[0] + 1 == row:
          return False
        if topleft[0] + 3 == row:
          return False
        board[topleft[0]+1][topleft[1]] = '*'
        mines_left -=1
    else:
      tmp = min(row-2,mines_left+topleft[0])
      for i in xrange(tmp):
        board[i][topleft[1]] = '*'
      mines_left -= tmp - topleft[0]
      if mines_left > 0:
        if topleft[1] + 1 == col:
          return False
        if topleft[1] + 3 == col:
          return False
        board[topleft[0]][topleft[1]+1] = '*'
        mines_left -=1
    if mines_left > 0:
      Tracer()()

    boola = False
    boolb = False
    boolc = False
    if row - 2 >=0 and board[row-2][col-1] == '*':
      boola = True
    if col - 2 >=0 and board[row-1][col-2] == '*':
      boolb = True
    if col - 2 >=0 and row - 2 >=0 and board[row-2][col-2] == '*':
      boolc = True
    if boola and boolb and boolc:
      board[row-1][col-1] = 'c'
      return True
    elif boola or boolb or boolc:
      return False
    board[row-1][col-1] = 'c'
    return True

# * . .
# 1 2 .
# 0 1 *

# c . .
# . . *

# c 1 .
# 0 1 *

# * * . .
# 2 2 2 .
# 0 0 1 *

# * * . .
# 2 2 1 .
# 0 0 1 .
# 0 0 1 *

# * * 1 0
# * 2 1 0
# 1 1 0 0
# 0 0 0 0

# * * 1 0 0
# 2 2 1 0 0
# 0 0 0 1 1
# 0 0 0 1 *

def minesweeper(f):
  soln = ''
  cases = int(f.readline())
  for case in xrange(cases):
    input_case = f.readline().split(' ')
    input_case = [int(x) for x in input_case]
    row = input_case[0]
    col = input_case[1]
    mines = input_case[2]
    imp = True
    if row == 1:
      board = ['*']*mines + ['.']*(col-1-mines) + ['c']
      board = [board]
    elif col == 1:
      board = [['.']*col for r in xrange(row)]
      board[row-1][0] = 'c'
      for i in xrange(mines):
        board[i][0] = '*'
    elif col*row-1 == mines:
      board = [['*']*col for r in xrange(row)]
      board[row-1][col-1] = 'c'
    elif col*row == mines:
      imp = False
    else:
      mines_left = mines
      board = [['.']*col for r in xrange(row)]
      topleft = [0,0]
      rowrem = row
      colrem = col
      while mines_left >= min(rowrem, colrem):
        reduct = max(rowrem, colrem)
        if reduct == rowrem:
          board[topleft[0]] = ['*']  * col
          topleft[0] += 1
          mines_left -= colrem
          rowrem -=1
        else:
          for i in xrange(row):
            board[i][topleft[1]] = '*'
          topleft[1] += 1
          mines_left -= rowrem
          colrem -=1
      imp = fillboard(board, topleft, mines_left, rowrem, colrem)
    # printboard(board)
    # print imp
    # print '{0} {1} {2}'.format(row, col, mines)
    # Tracer()()
    if imp:
      board = [''.join(x) for x in board]
      soln += 'Case #{0}:\n{1}\n'.format(case+1, '\n'.join(board))
    else:
      soln += 'Case #{0}:\nImpossible\n'.format(case+1)
  return soln

def writeOutput(file, soln):
  file.write(soln)
  file.close()

if __name__ == '__main__':
  f = open(sys.argv[1])
  soln = minesweeper(f)
  f.close()
  g = open("output.txt", "w")
  writeOutput(g, soln)

