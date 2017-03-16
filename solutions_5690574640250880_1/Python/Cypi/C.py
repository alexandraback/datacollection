def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

_T = readint()
for _t in range(_T):
  print 'Case #%i:'%(_t+1)

  R, C, M = readarray(int)
  F = R*C-M

  if R == 1:
    print 'c'+'.'*(C-M-1)+'*'*M
  elif C == 1:
    print 'c'
    for i in range(R-M-1):
      print '.'
    for i in range(M):
      print '*'
  elif F == 1:
    print 'c'+'*'*(C-1)
    for i in range(R-1):
      print '*'*C
  elif M == 0:
    print 'c'+'.'*(C-1)
    for i in range(R-1):
      print '.'*C
  elif F < 4:
    print 'Impossible'
  elif (C == 2 or R == 2) and (F%2 == 1):
    print 'Impossible'
  elif C == 2:
    print 'c.'
    for i in range(F/2-1):
      print '..'
    for i in range(R-F/2):
      print '**'
  elif R == 2:
    print 'c'+'.'*(F/2-1)+'*'*(C-F/2)
    print '.'*(F/2)+'*'*(C-F/2)
  elif F == 5 or F == 7:
    print 'Impossible'
  elif F < 7:
    r = 0
    print 'c.'+'*'*(C-2)
    r += 1
    for i in range(F/2-1):
      print '..'+'*'*(C-2)
      r += 1
    for i in range(R-r):
      print '*'*C
  elif F == 8:
    print 'c..'+'*'*(C-3)
    print '...'+'*'*(C-3)
    print '..'+'*'*(C-2)
    for i in range(R-3):
      print '*'*C
  else:
    #R >= 3 and C >= 3 and F >= 9
    
    mR = max(R, C)
    mC = min(R, C)
    G = [['*']*mC for i in range(mR)]
    if F <= 2*mR:
      for i in range(2):
        for j in range(3):
          G[i][j] = '.'
      if F%2 == 1:
        G[2][2] = '.'
      for i in range((F-6)/2):
        G[i+2][0] = '.'
        G[i+2][1] = '.'
    else:
      for i in range(mR):
        G[i][0] = '.'
        G[i][1] = '.'
      F -= 2*mR
      c = F/mR
      rem = F%mR
      for i in range(mR):
        for j in range(c):
          G[i][j+2] = '.'
      if rem >= 2:
        for i in range(rem):
          G[i][c+2] = '.'
      elif rem == 1:
        G[mR-1][c+1] = '*'
        G[0][c+2] = '.'
        G[1][c+2] = '.'
        if c == 0:
          G[mR-1][0] = '*'
          G[2][c+2] = '.'

    G[0][0] = 'c'
    if R >= C:
      for i in range(R):
        s = ''
        for j in range(C):
          s += G[i][j]
        print s
    else:
      for i in range(R):
        s = ''
        for j in range(C):
          s += G[j][i]
        print s
