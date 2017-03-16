
s = open("B-small-attempt0.in").read().split("\n")


T = int(s[0])
for t in range(1, T+1):
  X, Y = map(int, s[t].split())
  x0, y0 = 0, 0
  step = 1
  dir = 'E'
  jump = []
  while x0 != X:
    if dir == 'E':
      jump.append('E')
      x0 += step
      dir = 'W'
    else:
      jump.append('W')
      x0 -= step
      dir = 'E'
    step += 1
  if y0 != Y:
    if -step < Y < step:
      if Y > 0:
        jump.append('S')
        y0 -= step
      else:
        jump.append('N')
        y0 += step
      step += 1
    dir = 'N'
    while y0 != Y:
      if dir == 'N':
        jump.append('N')
        y0 += step
        dir = 'S'
      else:
        jump.append('S')
        y0 -= step
        dir = 'N'
      step += 1
  print "Case #"+str(t)+": "+"".join(jump)





