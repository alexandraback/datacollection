def win(temp):
       """Returns "X won" if X won, "O won" if O won, 0 if neither.
       Note: temp must be sorted."""
       if temp == ['T','X','X','X'] or temp == ['X','X','X','X']:
              return "X won"
       if temp == ['O','O','O','T'] or temp == ['O','O','O','O']:
              return "O won"
       return 0

def check(board):
       """Returns state of board."""

       # check diagonals
       temp = [board[0][0], board[1][1], board[2][2], board[3][3]]
       temp.sort()
       state = win(temp)
       if state:
              return state
       temp = [board[0][3], board[1][2], board[2][1], board[3][0]]
       temp.sort()
       state = win(temp)
       if state:
              return state
       
       # check horizontals
       for line in board:
              temp = line[:]
              temp.sort()
              state = win(temp)
              if state:
                     return state

       # check verticals
       for i in range(4):
              temp = [board[0][i], board[1][i], board[2][i], board[3][i]]
              temp.sort()
              state = win(temp)
              if state:
                     return state

       # check if board is full or not
       for line in board:
              if '.' in line:
                     return "Game has not completed"

       return "Draw"


f = open("A-large.in", "r")
g = open("A-large-ans0.txt", "w")

N = int(f.readline())
k = 0
while k < N:
    # parse board
    board = []
    for i in range(4):
           temp = f.readline().strip()
           board.append(list(temp))

    state = check(board)


    g.write("Case #" + str(k+1) + ": " + state + "\n")

    # move on to the next case
    f.readline()
    k += 1

f.close()
g.close()

