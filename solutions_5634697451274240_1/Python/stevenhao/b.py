r = raw_input
T = int(r())

def solve():
  s = r() + '+'
  diffs = [x for x in range(len(s) - 1) if s[x] != s[x + 1]]
  return len(diffs)

for t in range(1, T + 1):
  ans = solve()
  print 'Case #%d: %s' % (t, ans)
