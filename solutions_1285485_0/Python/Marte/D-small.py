import sys
import string
import fractions
inp = sys.stdin
T = int(inp.readline())

def dist2(pos_dist):
  return 2*pos_dist - 1

def ok(p1, p2, d):
  return p1**2 + p2**2 <= d*d

def gen(tot, z):
  w = (tot-z)*2
  z = z*2
  offset = 0
  noffset = 0
  yield offset
  while 1:
    offset += z
    noffset -= w
    yield offset
    yield noffset
    z, w = w, z

def reduce(a, b):
  g = abs(fractions.gcd(a, b))
  return a/g, b/g

for cas in xrange(1, T + 1):
  print "Case #%d:" % cas,
  h, w, d = map(int, inp.readline().strip().split(' '))
  pos_x = -1
  pos_y = -1
  for i in xrange(h):
    x = inp.readline().strip().find('X')
    if x >= 0:
      pos_x = x
      pos_y = i
  height = (h-2)*2
  width = (w-2)*2
  off_y = dist2(pos_y)
  off_x = dist2(pos_x)
  d2 = d*2
  c = 0
  is_over2 = 0
  added = set()
  for y in gen(height, off_y):
    is_over = 0
    has = False
    for x in gen(width, off_x):
      if x == 0 == y:
        continue
      #print y, x
      if ok(x, y, d2):
        has = True
        rep = reduce(x, y)
        if rep not in added:
          added.add(rep)
          c += 1
      else:
        is_over += 1
        if is_over > 2:
          break
    if not has:
      is_over2 += 1
      if is_over2 > 2:
        break
  print c

