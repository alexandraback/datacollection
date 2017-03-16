_T = int(raw_input())
for _t in range(1, _T+1):

  K, C, S = map(int, raw_input().split())

  if S*C < K:
    res = 'IMPOSSIBLE'
  else:
    res = []
    
    for i in range(0, K, C):
      n = 0
      for j in range(i, min(i+C, K)):
        n *= K
        n += j
      res.append(n+1)

    res = ' '.join(map(str, res))

  print 'Case #{}: {}'.format(_t, res)
