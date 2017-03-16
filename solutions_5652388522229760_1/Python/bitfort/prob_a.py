

def solv(n):
  if n == 0:
    return None
  notseen = [str(k) for k in xrange(10)]
  for i in xrange(1, 500000000000):
    x = n * i
    s = str(x)
    notseen = filter(lambda k: k not in s, notseen)
    if len(notseen) == 0:
      return x
  return None


t = raw_input()

for n in xrange(int(t)):
  v = int(raw_input())
  ans = solv(v)
  if ans is None:
    ans = 'INSOMNIA'
  print 'Case #{}: {}'.format(n + 1, ans)
