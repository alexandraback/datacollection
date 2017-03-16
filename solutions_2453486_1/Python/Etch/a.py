def isWinner(p, board):
  isP = lambda x: x == p or x == 'T'
  allP = lambda x: sum(map(isP, x)) == 4

  h = any(map(allP, board))
  v = any(map(allP, zip(*board)))
  d1 = allP([board[i][i] for i in range(4)])
  d2 = allP([board[i][3-i] for i in range(4)])
  return h or v or d1 or d2

K = int(raw_input())
for k in range(1, K+1):
  board = [raw_input() for i in range(4)]
  raw_input()
  print 'Case #%d:' % k,
  print ('X won' if isWinner('X', board)
    else 'O won' if isWinner('O', board)
    else 'Draw' if sum(map(lambda x: x == '.', ''.join(board))) == 0
    else 'Game has not completed')
