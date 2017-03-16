T = int(raw_input())
N = 4
for i in xrange(T):
  board = N*['']
  row_sums = [[0, 0, 0] for j in xrange(N)]
  column_sums = [[0, 0, 0] for j in xrange(N)]
  diagonal_sums = [[0, 0, 0] for j in xrange(2)]
  x_won = False
  o_won = False
  not_completed = False
  for j in xrange(N):
    board[j] = raw_input().strip()

  for j in xrange(N):
    for k in xrange(N):
      if board[j][k] == 'X':
        row_sums[j][0] += 1
        column_sums[k][0] += 1
      elif board[j][k] == 'O':
        row_sums[j][1] += 1
        column_sums[k][1] += 1
      elif board[j][k] == 'T':
        row_sums[j][2] += 1
        column_sums[k][2] += 1
      elif board[j][k] == '.':
        not_completed = True

  for j in xrange(N):
    if board[j][j] == 'X':
      diagonal_sums[0][0] += 1
    elif board[j][j] == 'O':
      diagonal_sums[0][1] += 1
    elif board[j][j] == 'T':
      diagonal_sums[0][2] += 1
    if board[N - 1 - j][j] == 'X':
      diagonal_sums[1][0] += 1
    elif board[N - 1 - j][j] == 'O':
      diagonal_sums[1][1] += 1
    elif board[N - 1 - j][j] == 'T':
      diagonal_sums[1][2] += 1


  for j in xrange(N):
    if row_sums[j][0] + row_sums[j][2] == N or column_sums[j][0] + column_sums[j][2] == N:
      x_won = True
      break
    elif row_sums[j][1] + row_sums[j][2] == N or column_sums[j][1] + column_sums[j][2] == N:
      o_won = True
      break
  for j in xrange(2):
    if diagonal_sums[j][0] + diagonal_sums[j][2] == N:
      x_won = True
      break
    elif diagonal_sums[j][1] + diagonal_sums[j][2] == N:
      o_won = True
      break
  if x_won:
    print 'Case #%d: X won' % (i + 1)
  elif o_won:
    print 'Case #%d: O won' % (i + 1)
  elif not_completed:
    print 'Case #%d: Game has not completed' % (i + 1)
  else:
    print 'Case #%d: Draw' % (i + 1)
  raw_input()
