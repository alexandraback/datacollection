def b(x, y):
  r = ''
  r += 'WE'*x if x >= 0 else 'EW'*(-x)
  r += 'SN'*y if y >= 0 else 'NS'*(-y)
  return r


f = open('b-small.in')
o = open('b-small.out', 'w')
n = int(f.readline())
for i in xrange(n):
  x, y = [int(c) for c in f.readline().split()]
  o.write('Case #%d: %s\n' % (i+1, b(x, y)))
o.close()
f.close()
