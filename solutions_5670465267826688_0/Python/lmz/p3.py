import sys

def mult_abs(a, b):
  if a == '1': return (b, 1)
  if b == '1': return (a, 1)
  if a == 'i' and b == 'i': return ('1', -1)
  if a == 'i' and b == 'j': return ('k', 1)
  if a == 'i' and b == 'k': return ('j', -1)
  if a == 'j' and b == 'i': return ('k', -1)
  if a == 'j' and b == 'j': return ('1', -1)
  if a == 'j' and b == 'k': return ('i', 1)
  if a == 'k' and b == 'i': return ('j', 1)
  if a == 'k' and b == 'j': return ('i', -1)
  if a == 'k' and b == 'k': return ('1', -1)

def mult((a, sa), (b, sb)):
  (p, sp) = mult_abs(a, b)
  return (p, sp*sa*sb)

tc = int(sys.stdin.readline())

for tmp_tc in xrange(tc):
  [ L, X ] = map(lambda x: int(x), sys.stdin.readline().rstrip('\n').split(' '))
  ws = sys.stdin.readline().rstrip('\n')
  ws = ws * X

  current = ('1', 1)
  ok_i, ok_j, ok_k = False, False, False
  for w in ws:
    current = mult(current, (w, 1))
    if current == ('i', 1):
      ok_i = True
    if ok_i and current == ('k', 1):
      ok_j = True

  res = "YES" if ok_j and current == ('1', -1) else "NO"

  print "Case #%d: %s" % (tmp_tc + 1, res)
