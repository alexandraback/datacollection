
def test(x, k):
  return (x >> k) & 1

def getPrimeDiv(x):
  d = 2
  while d * d <= x:
    if x % d == 0:
      return d
    d += 1
    if d > 1000:
      break
  return -1

def __main__():
  n = 32
  need = 500
  L = 2**31 + 2**28 + 2**26
  R = 2**32
  for x in xrange(L, R):
    if test(x, 0) == 0:
      continue
    if test(x, n - 1) == 0:
      continue
    bad = False
    pdivs = []
    for base in xrange(2, 11):
      v = 0
      for i in xrange(n):
        v *= base
        v += test(x, i)
      prime = getPrimeDiv(v)
      if prime == -1:
        bad = True
      pdivs.append(prime)
    if bad == False:
      print ''.join(str(test(x, i)) for i in xrange(n)), ' '.join(str(pdivs[i]) for i in xrange(len(pdivs)))
      need -= 1
      if need == 0:
        break

__main__()
