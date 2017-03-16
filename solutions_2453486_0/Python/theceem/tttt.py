#!/usr/bin/env python
import sys

def read_test_case(f):
  # read board and following empty line
  board = [f.readline().strip() for i in range(4)]
  assert not f.readline().strip(), "Each test case is followed by an empty line."
  return board

def analyze_quad(s):
  for player in ['X', 'O']:
    if s.count(player) == 4 or (s.count(player) == 3 and s.count('T') == 1):
      return '%s won' % player

def analyze(board):
  # "if there is a row, column or a diagonal containing 4 of that player's symbols,
  #  or containing 3 of her symbols and the 'T' symbol,
  #  she wins and the game ends"

  # collect quads to test
  quads = list(board)   # rows
  for i in range(4):
    quads.append([board[j][i] for j in range(4)])   # columns
  quads.append([board[i][i] for i in range(4)])     # principal diagonal
  quads.append([board[i][3-i] for i in range(4)])   # other diagonal

  # test each quad
  for quad in quads:
    result = analyze_quad(quad)
    if result:
      return result

  # "if all of the fields are filled with symbols and nobody won, the game ends in a draw"
  if not '.' in ''.join(board):
    return 'Draw'

  return 'Game has not completed'

# process all tests
test_count = int(sys.stdin.readline())
for i in range(test_count):
  board = read_test_case(sys.stdin)
  print 'Case #%d: %s' % (i+1, analyze(board))
