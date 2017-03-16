#! /usr/bin/env python


def solve(size, others):
  others.sort()
  moves = solveM(int(size), others, 0)
  return moves

def solveM(size, others, moves):
  if not others:
    return moves
  h = int(others[0])
  if (h < size):
    return solveM(size+h, others[1:], moves)
  else:
    A = moves + len(others)
    if size < 2:
      return A
    else:
      B = solveM(size*2-1, others, moves+1)
      return min(A, B)

#
# MAIN FUNCTION
#

# open input
with open('A-large.in', 'r') as f:
  numberCases = f.readline().strip()

  for i in range(0, int(numberCases)):
    size, nOthers = f.readline().split()
    others = [int(x) for x in f.readline().split()]
    moves = solve(size, others)
    print("Case #" + str(i+1) + ": " + str(moves))