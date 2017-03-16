for tc in xrange(int(raw_input())):
  print("Case #{}:".format(tc + 1))
  r, c, m = map(int, raw_input().split())

  f = [['*'] * c for i in xrange(r)]
  f[0][0] = '.'
  mask = [[0] * c for i in xrange(r)]

  def go(p, k):
    if k < m:
      return False
    if k == m:
      return True
    for i in xrange(r):
      for j in xrange(c):
        if f[i][j] == '.':
          flag = False
          for di in xrange(-1, 2):
            for dj in xrange(-1, 2):
              if di | dj != 0:
                ii = i + di
                jj = j + dj
                if ii >= 0 and ii < r and jj >= 0 and jj < c:
                  if f[ii][jj] == '*' and mask[ii][jj] == 0:
                    flag = True
                    f[ii][jj] = '.'
                    mask[ii][jj] = p
                    k -= 1
          if flag:
            if go(p + 1, k):
              return True
          for di in xrange(-1, 2):
            for dj in xrange(-1, 2):
              if di | dj != 0:
                ii = i + di
                jj = j + dj
                if ii >= 0 and ii < r and jj >= 0 and jj < c:
                  if f[ii][jj] == '.' and mask[ii][jj] == p:
                    f[ii][jj] = '*'
                    mask[ii][jj] = 0
                    k += 1
    return False

  if go(1, r * c - 1):
    f[0][0] = 'c'
    for i in xrange(r):
      print str(f[i]).translate(None, "[, ]'")
  else:
    print "Impossible"