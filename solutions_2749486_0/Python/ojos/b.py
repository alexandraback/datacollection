NNN = int(raw_input())
for nnn in xrange(1, NNN+1):
  print "Case #%d:" % (nnn),
  X, Y = [int(x) for x in raw_input().split()]
  step = 1
  x, y = 0, 0
  xdiff, ydiff = 0, 0
  result = ''
  if X < 0:
    while x - step >= X:
      result += 'W'
      x -= step
      step += 1
    xdiff = x - X
  elif X > 0:
    while x + step <= X:
      result += 'E'
      x += step
      step += 1
    xdiff = X - x
  if Y < 0:
    while y - step >= Y:
      result += 'S'
      y -= step
      step += 1
    ydiff = y - Y
  elif Y > 0:
    while y + step <= Y:
      result += 'N'
      y += step
      step += 1
    ydiff = Y - y
  if X > 0:
    result += 'WE' * xdiff
  elif X < 0:
    result += 'EW' * xdiff
  if Y > 0:
    result += 'SN' * ydiff
  elif Y < 0:
    result += 'NS' * ydiff

  print result

