import sys
inp = sys.stdin

def con(s):
  m = 0
  c = 0
  for l in s:
    if l in 'aeiou':
      c = 0
    else:
      c += 1
      m = max(m, c)
  return m

T = int(inp.readline())
for cas in xrange(1, T + 1):
  print "Case #%d:" % cas,
  s, n = inp.readline().split()
  n = int(n)
  L = len(s)
  ans = 0
  for i in xrange(L):
    for j in xrange(i+1, L+1):
      a = s[i:j]
      if con(a) >= n:
        ans += 1
  print ans
