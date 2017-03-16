def take(p, x, y):
  if x<0 or y<0 or x>=len(p[0]) or y>=len(p): return None
  else: return p[y][x]

def flood(p, x, y):
  if x<0 or y<0 or x>=len(p[0]) or y>=len(p) or p[y][x] =='-': return
  p[y][x] = '-'
  n = [(x,y+1), (x,y-1), (x+1,y), (x+1,y+1), (x+1,y-1), (x-1,y), (x-1,y+1), (x-1,y-1)]
  if [take(p,nx,ny) for nx,ny in n].count('*')==0:
    for nx, ny in n:
      flood(p, nx, ny)

T = int(raw_input())
for t in range(T):
  R,C,M = (int(x) for x in raw_input().split())
  F = R*C - M
  p = [['*']*C for i in range(R)]
  if F == 1:
    ok = True
  elif C == 1:
    for i in range(1, F): p[i][0] = '.'
    ok = True
  elif R == 1:
    for i in range(1, F): p[0][i] = '.'
    ok = True
  elif C == 2:
    for i in range(F//2): p[i][0] = p[i][1] = '.'
    ok = F%2 == 0 and F > 2
  elif R == 2:
    for i in range(F//2): p[0][i] = p[1][i] = '.'
    ok = F%2 == 0 and F > 2
  else:
    ok = (F%2 == 0 and F > 2) or (F%2 == 1 and F >= 9)
    if F%2 == 0 and F > 2:
      i = 0
      while F > 0 and i < R:
        p[i][0] = p[i][1] = '.'
        F -= 2
        i += 1
      c = 2
      while F > 0:
        i = 0
        while F > 0 and i+1 < R:
          p[i][c] = p[i+1][c] = '.'
          F -= 2
          i += 2
        if F >= 2 and p[R-1][c] == '*' and p[R-1][c-1] == '*':
          F -= 2
          p[R-1][c] = p[R-1][c-1] = '.'
        c += 1
    elif F%2 == 1 and F >= 9:
      p[0][1] = p[0][2] = p[1][0] = p[1][1] = p[1][2] = p[2][0] = p[2][1] = p[2][2] = '.'
      F -= 9
      i = 3
      while F > 0 and i < R:
        p[i][0] = p[i][1] = '.'
        F -= 2
        i += 1
      i = 3
      while F > 0 and i+1 < R:
        p[i][2] = p[i+1][2] = '.'
        F -= 2
        i += 2
      c = 3
      while F > 0:
        i = 0
        while F > 0 and i+1 < R:
          p[i][c] = p[i+1][c] = '.'
          F -= 2
          i += 2
          if F > 0 and p[R-1][c-1] == '*':
            p[i][c] = p[R-1][c-1] = '.'
            F -= 2
            i += 1
        c += 1

  print "Case #%i:"%(t+1)
  if not ok:
    print "Impossible"
  else:
    p[0][0]='c'
    s = "\n".join("".join(r) for r in p)
    print s
    assert(s.count('*') == M)
    flood(p, 0, 0)
    s = "\n".join("".join(r) for r in p)
    assert(s.count('.') == 0)


