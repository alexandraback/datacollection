import sys

PLAYERS = "XO"
WILDS = "T"
EMPTY = "."

BOARD_SIZE = 4

def isWin(cells, player):
   return all(cell in player + WILDS for cell in cells)

def analyzeBoard(board):
   assert len(board) == len(board[0])
   for player in PLAYERS:
      # check rows
      for row in board:
         if isWin(row, player):
            return "%s won" % player

      # check columns, thank you dbox programming spelling bee
      for column in zip(*board):
         if isWin(column, player):
            return "%s won" % player

      # check diagonal 1
      if isWin([board[i][i] for i in range(BOARD_SIZE)], player):
         return "%s won" % player

      # check diagonal 2
      if isWin([board[BOARD_SIZE - 1 - i][i] for i in range(BOARD_SIZE)], player):
         return "%s won" % player

   # neither player won, are there any cells left?
   for row in board:
      for cell in row:
         if cell == EMPTY:
            return "Game has not completed"

   # cat's game
   return "Draw"

def main():
   lines = open(sys.argv[1], 'r').read().split("\n")
   testCases = lines.pop(0)
   testCases = int(testCases)

   for i in range(testCases):
      board = []
      for nthRow in range(BOARD_SIZE):
         board.append(lines.pop(0))
      status = analyzeBoard(board)
      print "Case #%s: %s" % ( i+1, status )
      lines.pop(0) # there's a newline after each board

if __name__ == "__main__":
   main()
