r = raw_input
T = int(r())

def solve():
  n = int(r())
  if n == 0:
    return 'INSOMNIA'
  seen = set()
  nxt = 0
  while len(seen) < 10:
    nxt += n
    for ch in str(nxt):
      seen.add(ch)
  return nxt

for t in range(1, T + 1):
  ans = solve()
  print 'Case #%d: %s' % (t, ans)
