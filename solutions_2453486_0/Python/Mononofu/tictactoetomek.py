import sys

num_cases = int(sys.stdin.readline())


def transpose(matrix):
  return zip(*matrix)


def check_row(row):
  if '.' in row or ('X' in row and 'O' in row):
    return None
  if row[0] == 'T':
    return row[1]
  else:
    return row[0]


def diagonals(board):
  return [[board[0][0], board[1][1], board[2][2], board[3][3]],
          [board[3][0], board[2][1], board[1][2], board[0][3]]]


def process_board(board):
  for row in board + transpose(board) + diagonals(board):
    winner = check_row(row)
    if winner:
      print "%s won" % winner
      return

  if '.' in "".join(board):
    print "Game has not completed"
  else:
    print "Draw"

for i in range(num_cases):
  board = []
  for j in range(4):
    board.append(sys.stdin.readline().strip())
  print "Case #%d:" % (i + 1),
  process_board(board)
  # skip emtpy line
  sys.stdin.readline()
