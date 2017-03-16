NNN = int(raw_input())
for nnn in xrange(1, NNN+1):
  print "Case #%d:" % (nnn),
  N = int(raw_input())
  d  = [0] * N  # day of first attack
  n  = [0] * N  # num attack
  w  = [0] * N  # west (-ve x) boundary of initial attack
  e  = [0] * N  # east (+ve x) boundary of initial attack
  s  = [0] * N  # strength of initial attack
  dd = [0] * N  # days between attacks (d2 = d1 + dd + 1)
  dp = [0] * N  # change in position
  ds = [0] * N  # change in strength

  min_d = 0
  for i in xrange(N):
    I = [int(x) for x in raw_input().split()]
    d [i] = I[0]
    n [i] = I[1]
    w [i] = I[2]
    e [i] = I[3]
    s [i] = I[4]
    dd[i] = I[5]
    dp[i] = I[6]
    ds[i] = I[7]
    if min_d == -1:
      min_d = d[i]
    elif min_d > d[i]:
      min_d = d[i]

  result = 0
  W = [0] * 801
  new_W = [0] * 801
  day = min_d
  finished = 0
  while finished < N:
    for i in xrange(N):
      if n[i] > 0 and d[i] == day:
        flag = False
        for j in xrange((w[i]+200)*2, (e[i]+200)*2+1):
          if W[j] < s[i]:
            flag = True
            if new_W[j] < s[i]:
              new_W[j] = s[i]
        if flag:
          result += 1
        if n[i] > 1:
          d[i] += dd[i]
          w[i] += dp[i]
          e[i] += dp[i]
          s[i] += ds[i]
        else:
          finished += 1
        n[i] -= 1
    min_d = -1
    for i in xrange(N):
      if n[i] > 0:
        if min_d == -1:
          min_d = d[i]
        elif min_d > d[i]:
          min_d = d[i]
    day = min_d
    W = new_W[:]

  print result

