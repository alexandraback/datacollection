def isPossible(lawn):
  row = lambda r: [lawn[r][i] for i in range(M)]
  col = lambda c: [lawn[i][c] for i in range(N)]
  return all(max(row(r)) == lawn[r][c] or max(col(c)) == lawn[r][c]
             for r in range(N) for c in range(M))

K = int(raw_input())

for k in range(1, K+1):
  N, M = map(int, raw_input().split())
  lawn = [raw_input().split() for i in range(N)]
  print 'Case #%d:' % k,
  print 'YES' if isPossible(lawn) else 'NO'
