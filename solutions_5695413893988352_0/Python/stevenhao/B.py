from collections import *

r = raw_input

def solve(a, b):
  a, b = map(list, (a, b))
  n = len(a)
  i = 0
  while i < n and (a[i] == '?' or b[i] == '?' or a[i] == b[i]):
    if a[i] == '?':
      a[i] = b[i]
    if b[i] == '?':
      b[i] = a[i]
    if a[i] == '?':
      a[i], b[i] = '0', '0'
    i += 1
  if i < n:
    if a[i] < b[i]:
      while i < n:
        if a[i] == '?':
          a[i] = '9'
        if b[i] == '?':
          b[i] = '0'
        i += 1
    else:
      while i < n:
        if a[i] == '?':
          a[i] = '0'
        if b[i] == '?':
          b[i] = '9'
        i += 1
  return ' '.join((''.join(a), ''.join(b)))




T = int(r())
for t in range(1, T + 1):
  a, b = r().split()
  ans = solve(a, b)
  print 'Case #%d: %s' % (t, ans)

