nc = input()
for ci in range(1, nc+1):
  R, C, M = map(int, raw_input().split())
  f = R * C - M
  res = ['' for i in range(R)]
  if f == 1:
    res[0] = 'c' + '*' * (C - 1)
    for i in range(1, R):
      res[i] = '*' * C
  elif R == 1:
    res = ['c' + '.' * (f-1) + '*' * M]
  elif C == 1:
    res[0] = 'c'
    for i in range(1, f):
      res[i] = '.'
    for i in range(f, R):
      res[i] = '*'
  elif R == 2:
    if f == 2 or f % 2 == 1:
      res = ['Impossible']
    else:
      res[0] = 'c' + '.' * (f / 2 -1) + '*' * (M / 2)
      res[1] = '.' * (f / 2) + '*' * (M / 2)
  elif C == 2:
    if f == 2 or f % 2 == 1:
      res = ['Impossible']
    else:
      for i in range(R):
        if i == 0:
          res[i] = 'c.'
        elif i < f/2:
          res[i] = '..'
        else:
          res[i] = '**'
  else:
    if f in [2, 3, 5, 7]:
      res = ['Impossible']
    else:
      m = R * C 
      a = [[True] * C for i in range(R)] 
      a[0][0] = False
      a[0][1] = False
      a[1][0] = False
      a[1][1] = False
      m -= 4
      k = 1
      while k + 1 < R or k + 1 < C:
        if k + 1 < R and m - 2 >= M:
          a[k + 1][0] = False
          a[k + 1][1] = False
          m -= 2
        if k + 1 < C and m - 2 >= M:
          a[0][k + 1] = False
          a[1][k + 1] = False
          m -= 2
        k += 1
      for i in range(1, R-1):
        for j in range(1, C-1):
          if m - 1 >= M:
            a[i+1][j+1] = False
            m -= 1
      for i in range(R):
        s = ''
        for j in range(C):
          if (i, j) == (0,0):
            s +=  'c'
          elif a[i][j]:
            s += '*'
          else:
            s += '.'
        res[i] = s
  print 'Case #%d:' % ci
  print '\n'.join(res)
  
  
  
