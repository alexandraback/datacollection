#!/usr/bin/python2
#-*- coding: utf-8 -*-

def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

T = 3
O = 2
X = 1

def has_won(player, row):
  return len([x for x in row if x == player or x == T]) == 4

for test in range(readint()):
  print 'Case #%i:'%(test+1),
  if test > 0:
    raw_input()
  grid = []
  for i in range(4):
    line = raw_input()
    row = []
    for j in range(4):
      row.append(X if line[j] == 'X' else O if line[j] == 'O' else T if line[j] == 'T' else 0)
    grid.append(row)
  X_won = False
  O_won = False

  for i in range(4):
    X_won |= has_won(X, grid[i])
    O_won |= has_won(O, grid[i])
    X_won |= has_won(X, [grid[j][i] for j in range(4)])
    O_won |= has_won(O, [grid[j][i] for j in range(4)])
  X_won |= has_won(X, [grid[i][i] for i in range(4)])
  O_won |= has_won(O, [grid[i][i] for i in range(4)])
  X_won |= has_won(X, [grid[i][3-i] for i in range(4)])
  O_won |= has_won(O, [grid[i][3-i] for i in range(4)])

  if X_won:
    print 'X won'
  elif O_won:
    print 'O won'
  else:
    finished = True
    for i in range(4):
      for j in range(4):
        finished &= grid[i][j] != 0
    if finished:
      print 'Draw'
    else:
      print 'Game has not completed'
