# quala.py

#f = open('test', 'r')
f = open('A-large.in', 'r')

T = int(f.readline())

wins = (
((0,0),(0,1),(0,2),(0,3)),
((1,0),(1,1),(1,2),(1,3)),
((2,0),(2,1),(2,2),(2,3)),
((3,0),(3,1),(3,2),(3,3)),
((0,0),(1,0),(2,0),(3,0)),
((0,1),(1,1),(2,1),(3,1)),
((0,2),(1,2),(2,2),(3,2)),
((0,3),(1,3),(2,3),(3,3)),
((0,0),(1,1),(2,2),(3,3)),
((0,3),(1,2),(2,1),(3,0)))

def check_board(board):
  for win in wins:
    if all(board[x][y] in {'X', 'T'} for x,y in win):
      return 'X won'
    elif all(board[x][y] in {'O', 'T'} for x,y in win):
      return 'O won'
  
  if any('.' in board[i] for i in range(4)):
    return 'Game has not completed'
  else:
    return 'Draw'

for i in range(1, T+1):
  board = [f.readline()[:4] for j in range(4)]
  
  print 'Case #' + str(i) + ': ' + check_board(board)
  
  f.readline()
