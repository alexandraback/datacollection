
primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97]


def find_factor(k):
  for p in primes:
    if p >= k:
      return None
    if k % p == 0:
      return p
  return None


def populate_primes(n):
  for i in xrange(primes[-1], n+1):
    if find_factor(i) is None:
      primes.append(i)


def is_jamcoin(s):
  l = []
  for base in xrange(2, 11):
    f = find_factor(int(s, base))
    if f is None:
      return None, None
    l.append(f)
  return s, l


def print_soln((N, J)):
  x = (1 << (N-1)) + 1
  while J > 0:
    s, l = is_jamcoin(bin(x)[2:])
    if s is not None:
      print '{} {}'.format(s, ' '.join(map(str, l)))
      J -= 1
    x += 2


populate_primes(65536)

t = raw_input()

for n in xrange(int(t)):
  print 'Case #{}:'.format(n+1)
  print_soln(tuple(map(int, raw_input().split())))


