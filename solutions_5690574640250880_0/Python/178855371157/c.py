
import itertools
import sys

soln = [[[None] * (R*C) for C in range(0, 11)] for R in range(0, 11)]

def convert(board, click_r, click_c):
  R = len(board)
  C = len(board[0])
  ret = ''
  for r in range(0, R):
    ret += '\n'
    for c in range(0, C):
      if (r == click_r) and (c == click_c):
        ret += 'c'
      elif board[r][c]:
        ret += '*'
      else:
        ret += '.'
  return ret

def do(board):
  orig_board = board
  R = len(board)
  C = len(board[0])
  board = [[0] * (C+2)] + [(0,) + row + (0,) for row in board] + [[0] * (C+2)]

  # Compute counts and find the first 0.
  count = [[0] * (C+2) for r in range(0, R+2)]
  (r0, c0) = (-1, -1)
  (r_n0, c_n0) = (-1, -1)
  nonzeroes = 0
  zeroes = 0
  for r in range(1, R+1):
    for c in range(1, C+1):
      for dr in [-1, 0, 1]:
        for dc in [-1, 0, 1]:
          count[r][c] += board[r+dr][c+dc]
      if count[r][c] == 0:
        (r0, c0) = (r, c)
        zeroes += 1
      if (count[r][c] > 0) and not board[r][c]:
        (r_n0, c_n0) = (r, c)
        nonzeroes += 1

  # print zeroes, nonzeroes, (r0, c0)

  if (zeroes == 0) and (nonzeroes == 1):
    # We have a solution to the M == R*C - 1 case.
    if not soln[R][C][R*C-1]:
      soln[R][C][R*C-1] = convert(orig_board, r_n0-1, c_n0-1)

  # Flood fill.
  visited = [[False] * (C+2) for r in range(0, R+2)]
  q = [(r0, c0)]
  n = 0
  while q:
    (r, c) = q.pop()
    if visited[r][c]: continue
    visited[r][c] = True
    n += 1
    if count[r][c] != 0: continue
    for dr in [-1, 0, 1]:
      for dc in [-1, 0, 1]:
        if (r+dr < 1) or (r+dr > R) or (c+dc < 1) or (c+dc > C): continue
        if board[r+dr][c+dc]: continue
        q.append((r+dr,c+dc))

  # print n, visited

  if n == (zeroes + nonzeroes):
    # Success.
    M = R*C - n
    if not soln[R][C][M]:
      soln[R][C][M] = convert(orig_board, r0-1, c0-1)


def go(max_R, max_C):
  for R in range(1, max_R+1):
    for C in range(1, max_C+1):
      for board in itertools.combinations_with_replacement(apply(itertools.product, [[0, 1]] * C), R):
        do(board)

go(5, 5)

T = int(sys.stdin.readline())
for i in range(1, T+1):
    [R, C, M] = [int(n) for n in sys.stdin.readline()[:-1].split(' ')]
    if soln[R][C][M]:
      print "Case #{}:{}".format(i, soln[R][C][M])
    else:
      print "Case #{}:\nImpossible".format(i)

"""
Constraints:

 - The 0's are connected.
 - Every >0 borders a 0.  (Special case: there are no 0's and exactly one >0.)
 - The number of mines equals M.


 .....
 .000.
 ...0.
 .M.0.
 ...0.
 .000.
"""
