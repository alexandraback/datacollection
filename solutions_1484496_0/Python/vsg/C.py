def make_set(a, i):
  a = list(a)
  result = []
  while a and i > 0:
    x = a.pop()
    i, b = divmod(i, 2)
    if b:
      result.append(x)
  return set(result)

T = int(raw_input())
for t in xrange(T):
  a = [int(x) for x in raw_input().split()]
  a = a[1:]

  d = {}
  res = False
  for i in xrange(1, 2**20):
      s = make_set(a, i)
      ss = sum(s)
      if ss in d and s != d[ss]:
        res = True
        break
      d[ss] = s
  print "Case #%i:" % (t+1)
  if res:
    print " ".join(map(str, s))
    print " ".join(map(str, d[ss]))
  else:
    print "Impossible"
