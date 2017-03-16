#!/usr/bin/env python

import sys
from copy import deepcopy

def draw(board):
  print_click = True
  for r in board:
    for c in r:
      if print_click:
        print_click = False
        print 'c',
        continue 
      if c == 2:
        print '*',
      else:
        print '.',
    print

def stats(board):
  lucky = sum(r.count(0) for r in board)
  neigh = sum(r.count(1) for r in board)
  bomb = sum(r.count(2) for r in board)

  return [lucky, neigh, bomb]

def click(board, R, C, r, c):
  board[r][c] = 0
  
  prev_r = r-1
  next_r = r+1
  prev_c = c-1
  next_c = c+1

  if prev_r >= 0 and prev_c >= 0:
    if board[prev_r][prev_c] > 0:
      board[prev_r][prev_c] -= 1

  if prev_c >= 0:
    if board[r][prev_c] > 0:
      board[r][prev_c] -= 1

  if next_r < R and prev_c >= 0:
    if board[next_r][prev_c] > 0:
      board[next_r][prev_c] -= 1

  if prev_r >= 0:
    if board[prev_r][c] > 0:
      board[prev_r][c] -= 1
  
  if next_r < R:
    if board[next_r][c] > 0:
      board[next_r][c] -= 1

  if prev_r >= 0 and next_c < C:
    if board[prev_r][next_c] > 0:
      board[prev_r][next_c] -= 1

  if next_c < C:
    if board[r][next_c] > 0:
      board[r][next_c] -= 1
  
  if next_r < R and next_c < C:
    if board[next_r][next_c] > 0:
      board[next_r][next_c] -= 1

  return board

def click_where_we_can(board, R, C):
  res = []
  for r in range(R):
    for c in range(C):
      if board[r][c] == 1:
        res.append(click(deepcopy(board), R, C, r, c))

  return res

def solve(R, C, M):
  board = [[2 for c in range(C)] for r in range(R)]  

  # dirty hack ;)
  if R*C - M == 1:
    board = [[2 for c in range(C)] for r in range(R)]
    draw(board)
    return
  
  stack = [click(deepcopy(board), R, C, 0, 0) ]
 
  found = False
  final_res = None
  while stack:
     cur_board = stack.pop()
     lucky, neigh, bomb = stats(cur_board) 

     #print "Checking"
     #draw(cur_board)

     if bomb == M:
       found = True 
       final_res = cur_board
       break
     elif bomb > M:
       stack += click_where_we_can(cur_board, R, C)     

  if found:
    draw(final_res)
  else:
    print "Impossible"  

     


f = open(sys.argv[1], 'r')
T = int(f.readline())

for t in range(T):
  R, C, M = map(int, f.readline().strip().split())

  print "Case #%d:" % ( (t+1) )
  solve(R, C, M)
