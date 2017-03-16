T = int(raw_input())
for k in xrange(T):
  not_possible = False
  M, N = tuple([int(string) for string in raw_input().split(' ')])
  lawn = [[int(string) for string in raw_input().split(' ')]for i in xrange(M)]
  row_maxima = [0 for i in xrange(N)]
  column_maxima = [0 for i in xrange(M)]
  for i in xrange(M):
    for j in xrange(N):
      row_maxima[j] = max(row_maxima[j], lawn[i][j])
      column_maxima[i] = max(column_maxima[i], lawn[i][j])
  for i in xrange(M):
    for j in xrange(N):
      if  not (lawn[i][j] == row_maxima[j] or lawn[i][j] == column_maxima[i]):
        not_possible = True
        break
  if not_possible:
    print 'Case #%d: NO' % (k + 1)
  else:
    print 'Case #%d: YES' % (k + 1)
