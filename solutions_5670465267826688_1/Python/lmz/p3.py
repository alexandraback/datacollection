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

def fast_exp(x, n):
  if n == 0: return ('1', 1)
  if n % 2 == 0:
    tmp = fast_exp(x, n/2)
    return mult(tmp, tmp)
  return mult(x, fast_exp(x, n-1))

tc = int(sys.stdin.readline())

for tmp_tc in xrange(tc):
  [ L, X ] = map(lambda x: int(x), sys.stdin.readline().rstrip('\n').split(' '))
  ws = sys.stdin.readline().rstrip('\n')
  size = L * X

  current = ('1', 1)
  prods = [ current ]
  for w in ws:
    current = mult(current, (w, 1))
    prods.append(current)

  first_i = None
  last_k = None
  for u in xrange(min(20, X)):
    tmp = fast_exp(current, u)
    for i, p in enumerate(prods):
      if mult(tmp, p) == ('i', 1):
        first_i = u * X +i
        break
    if first_i != None: break

  for u in xrange(max(X-20, 0), X):
    tmp = fast_exp(current, u)
    for i, p in enumerate(prods):
      if mult(tmp, p) == ('k', 1):
        last_k = u * X + i

  total = fast_exp(current, X)


  ok = total == ('1', -1) and first_i != None and last_k != None and first_i < last_k

  res = "YES" if ok else "NO"

  print "Case #%d: %s" % (tmp_tc + 1, res)
