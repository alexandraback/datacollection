#! /usr/bin/python

import sys

def check_row(grid, row, player):
  won = True
  for i in range(4):
    if grid[row][i] != player and grid[row][i] != 'T':
      won = False
  return won

def check_col(grid, col, player):
  won = True
  for i in range(4):
    if grid[i][col] != player and grid[i][col] != 'T':
      won = False
  return won

def check_diag1(grid, player):
  won = True
  for i in range(4):
    if grid[i][i] != player and grid[i][i] != 'T':
      won = False
  return won

def check_diag2(grid, player):
  won = True
  for i in range(4):
    if grid[3-i][i] != player and grid[3-i][i] != 'T':
      won = False
  return won


def run():
  grid = []
  not_finished = False
  for i in range(4):
    row = list(sys.stdin.readline().strip())
    if '.' in row:
      not_finished = True

    grid.append(row)
  sys.stdin.readline()

  o_won = False
  x_won = False

  for i in range(4):
    o_won = o_won or check_row(grid, i, 'O')
    o_won = o_won or check_col(grid, i, 'O')
    x_won = x_won or check_row(grid, i, 'X')
    x_won = x_won or check_col(grid, i, 'X')

  o_won = o_won or check_diag1(grid, 'O') or check_diag2(grid, 'O')
  x_won = x_won or check_diag1(grid, 'X') or check_diag2(grid, 'X')

  if o_won and x_won:
    return "Error"

  if o_won:
    return "O won"
  if x_won:
    return "X won"
  if not_finished:
    return "Game has not completed"
  return "Draw"
 

cases = int(sys.stdin.readline())
for case in range(cases):
  print "Case #%d: %s"%(case+1, run())

