#!/usr/bin/python -tt

def won(board1):
  #4 rows
  row = ""
  for rownumber in xrange(4):
    if board1[rownumber*4:rownumber*4+4] == "1111": return 1
  #4 columns
  column = ""
  for columnnumber in xrange(4):
    if board1[0+columnnumber] + board1[4+columnnumber] + board1[8+columnnumber] + board1[12+columnnumber] == "1111": return 1
  #2 diagonals
  if board1[0] + board1[5] + board1[10] + board1[15] == "1111": return 1
  if board1[3] + board1[6] + board1[9] + board1[12] == "1111": return 1
  #else
  return 0
  


def main(board):
  #O won?
  boardO = board.replace("T","O").replace("O","1")
  if won(boardO) == 1: return "O won"

  #X won?
  boardX = board.replace("T","X").replace("X","1")
  if won(boardX) == 1: return "X won"

  #Game completed?
  if board.find(".") < 0:
    return "Draw"

  #else
  return "Game has not completed"


if __name__ == '__main__':
  import sys
  T = int(sys.stdin.readline())
  for i in xrange(T):
    board = ""
    for j in xrange(4):
      board = board + sys.stdin.readline().strip()
    blank_line = sys.stdin.readline()
    res = main(board)
    print "Case #%d: %s" % (i + 1, res)
