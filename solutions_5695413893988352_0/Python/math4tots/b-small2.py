try: input = raw_input
except NameError: pass

def subs(fmt, i, il):
  si = iter(str(i).zfill(il))
  chars = []
  for ch in fmt:
    if ch == '?':
      chars.append(next(si))
    else:
      chars.append(ch)
  return int(''.join(chars))

def solve(line):
  a, b = line.split()
  qa = a.count('?')
  qb = b.count('?')
  ba = bb = None

  if qa == 0 and qb == 0:
    ba = int(a)
    bb = int(b)
  elif qa == 0:
    xa = int(a)
    ib = 0
    while len(str(ib)) <= qb:
      xb = subs(b, ib, qb)
      if ba is None or abs(xa-xb) < abs(ba-bb):
        ba = xa
        bb = xb
      ib += 1
  elif qb == 0:
    xb = int(b)
    ia = 0
    while len(str(ia)) <= qa:
      xa = subs(a, ia, qa)
      if ba is None or abs(xa-xb) < abs(ba-bb):
        ba = xa
        bb = xb
      ia += 1
  else:
    ia = 0
    while len(str(ia)) <= qa:
      ib = 0
      while len(str(ib)) <= qb:
        xa = subs(a, ia, qa)
        xb = subs(b, ib, qb)
        if ba is None or abs(xa-xb) < abs(ba-bb):
          ba = xa
          bb = xb
        ib += 1
      ia += 1

  return '%s %s' % (str(ba).zfill(len(a)), str(bb).zfill(len(b)))

for i in range(1, 1+int(input())):
  print('Case #%d: %s' % (i, solve(input())))
