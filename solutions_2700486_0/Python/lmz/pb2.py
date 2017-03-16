import sys

def p(r, y, m, a, b):
  if b > y: return 1.0
  if r == 0: return 0.0
  if a == m:
    return p(r-1, y, m, a, b+1)
  if b == m:
    return p(r-1, y, m, a+1, b)
  left = p(r-1,y,m,a+1,b)
  right = p(r-1,y,m,a,b+1)
  return 0.5*(left+right)

def f(n, x, y):
  x = abs(x)
  tmp = 1
  layer = 1
  while True:
    tmp_ = tmp + 2*layer+3
    if tmp_ > n: break
    tmp = tmp_
    layer += 2
  h = layer
  remaining = n - tmp
  if y+x <= h-1: return 1.0
  if y+x <= h+1:
    if remaining <= y: return 0.0
    return p(remaining, y, h+1, 0, 0)
  return 0.0

samples = int(sys.stdin.readline().rstrip())
for i in range(samples):
  [n, x, y] = sys.stdin.readline().rstrip().split()
  print "Case #%d: %.8f" % (i+1, f(int(n), int(x), int(y)))
