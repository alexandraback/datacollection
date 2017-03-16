import sys
import itertools
sys.setrecursionlimit(10000)

MAXP = 1000
primes = []
is_prime = [ True ] * (1+MAXP)
for p in xrange(2, 1+MAXP):
  if is_prime[p]:
    primes.append(p)
    for q in xrange(p+p, 1+MAXP, p):
      is_prime[q] = False

def b2(n):
  res = []
  while n:
    res.append(str(n%2))
    n /= 2
  return ''.join(reversed(res))

def basis(w, b):
  res = 0
  bb = 1
  while w:
    res += bb * (w % 2)
    w /= 2
    bb *= b
  return res

tc = int(sys.stdin.readline().strip())

for tmp_tc in xrange(tc):
  [ N, J ] = map(lambda x: int(x), sys.stdin.readline().strip().split(' '))
  print "Case #%d:" % (1+tmp_tc)
  V = (1 << (N-1)) + 1
  for j in xrange(J):
    while True:
      divs = []
      ok = True
      for b in xrange(2, 11):
        tmp_div = None
        w = basis(V, b)
        for p in primes:
          if p >= w: break
          if w % p == 0:
            tmp_div = p
            break
        if tmp_div is None:
          ok = False
          break
        divs.append(tmp_div)
      if ok: break
      V += 2
    print "%s %s" % (b2(V), ' '.join([str(d) for d in divs]))
    V += 2

