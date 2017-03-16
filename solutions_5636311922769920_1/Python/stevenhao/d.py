r = raw_input
T = int(r())

def solve():
  k, c, s = map(int, r().split())
  if c * s < k:
    return 'IMPOSSIBLE'
  ans = []
  for i in range(0, k, c):
    x = 0
    for j in range(i, i + c):
      add = min(j, k - 1)
      x = x * k + add
    ans.append(x + 1)
  return ' '.join(map(str, ans))

for t in range(1, T + 1):
  ans = solve()
  print 'Case #%d: %s' % (t, ans)
