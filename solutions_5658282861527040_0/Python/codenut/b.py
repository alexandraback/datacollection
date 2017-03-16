fl = 'B-small-attempt0'
br = open(fl + '.in')
pw = open(fl + '.out', 'w')


f = lambda: map(int, br.readline().split())
t = f()[0]

def solve(a, b, k):
  r = 0
  for i in range(a):
    for j in range(b):
      if (i & j) < k:
        r += 1
  return r

for i in range(t):
  a, b, k = f()
  r = solve(a, b, k)
  print 'Case #%d: %d' % (i + 1, r)
  pw.write('Case #%d: %d\n' % (i + 1, r))
