#!/usr/bin/python3
from googlejam.tools import *

def printrow(row, repl='.'):
  return "".join([c if c != 'r' else repl for c in row.values()])
def printboard(grid, repl='.'):
  if not grid: return ""
  rows = []
  for row in grid.values():
    rows.append(printrow(row,repl))
  return "\n" + "\n".join(rows)

# c *  Only valid when too many mines
# * *

# c r  The next smallest absolutely required form
# r r  

# c r . *  spots = 5
# r r * *  INVALID for all but C == 1 or R == 1
# * * * *
# * * * *

# c r . *  spots = 6
# r r . *  Valid
# * * * *
# * * * *

# c r . *  spots = 7
# r r * *  INVALID for all but C == 1 or R == 1
# . . * *
# * * * *

# c r . *  spots = 8
# r r . *  Valid
# . . * *
# * * * *

# c r . .  spots = 8
# r r . .  Valid
# * * * *
# * * * *

# c r . .  spots = 10
# r r . .  requires row 3 to not fill first 2 cols
# . . * *  Valid
# * * * *

# c r . *  spots = 9, C 4 R 4
# r r . *  Valid, but requires special consideration on last 3 rows
# . . . *
# * * * *

# c r . .  spots = 9, C 4 R 4
# r r . *  Invalid, (old heuristic approach)
# . . * *  we can improve by backtracking when finding an odd amount 
# * * * *  of remaining mines on last two rows. Move mine from row 3

# c r . . ... *  general class of solutions using this heuristic
# r r . . ... * 
# . . . * ... *
# * * * * ... *

# a simple heuristic:

# handle cases R = 1, C = 1, unsolved = 1 seperately
# fill rows > 2 if can fill completely
# if printed all mines, then done
# for rows [0,1]:
#   fill columns from right to left
#   if unsolved is odd then move up to row[2] if possible (else impossible)
# quick impossible check:
#   unsolved in [2,3,5,7] 

impossible = [2,3,5,7]
def IMPOSSIBLE(msg,grid=None):
  #return "\nImpossible because {}\n{}".format(msg,printboard(grid))
  return "\nImpossible"
def specialcases(R,C,M,grid,spots):
  if spots <= 0: return IMPOSSIBLE("more mines than spots")
  if spots == 1:
    grid = {r:{c:"*" for c in range(C)} for r in range(R)}
    grid[0][0] = 'c'
    return printboard(grid)
  if R == 1: 
    for c in range(C)[C-M:]:
      grid[0][c] = '*'
    return printboard(grid)
  if C == 1:
    for r in range(R)[R-M:]:
      grid[r][0] = '*'
    return printboard(grid)
  if spots in impossible:
    return IMPOSSIBLE("impossible number of spots {}".format(spots))

class Jam:
  split = " "
  #flatten = True
  cases = line_cases(("R","C","M"))
  def solve(R,C,M):
    solution = Jam.solution(R,C,M)
    return solution #"M:{}, R:{}, C:{}\n{}".format(M,R,C,solution)
  def solution(R,C,M):
    R,C,M = map(lambda x:int(x[0]),[R,C,M])
    grid = {r:{c:"." for c in range(C)} for r in range(R)}
    grid[0][0] = 'c'
    spots = R*C - M
    special = specialcases(R,C,M,grid,spots)
    if special: return special
    remaining = M
    # fill up from bottom, except top two rows
    for r in reversed(range(R)[2:]):
      fill_to = 0 if remaining >= C else max(2,C-remaining)
      for c in range(C)[fill_to:]:
        grid[r][c] = '*'
        remaining -= 1
      if not remaining: return printboard(grid)
    # handle last two rows seperately
    # square it
    if remaining % 2: 
      if 2 in grid and 2 in grid[2]:
        if grid[2][0] == '.' and grid[2][1] == '.':
          assert grid[2][2] != '.'
          grid[2][2] = '.'
          remaining += 1
        else:
          assert grid[2][0] != '.'
          assert grid[2][1] != '.'
          assert grid[2][2] != '.'
          grid[2][0] = grid[2][1] = grid[2][2] = '.'
          remaining += 3
    # fill columns on right
    cols = remaining // 2
    for c in range(C)[C-cols:]:
      grid[0][c] = grid[1][c] = '*'
      remaining -= 2
    if remaining:
      return IMPOSSIBLE("no remaining spots {}".format(remaining),grid)
    return printboard(grid)
      
import googlejam.main
