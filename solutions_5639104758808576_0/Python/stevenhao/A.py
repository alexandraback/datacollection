def solve():
  x, y = raw_input().split()
  smax = int(x)
  ar = [int(_) for _ in y]

  cur, ans = 0, 0
  for i, cnt in enumerate(ar):
    if cur < i:
      ans += i - cur
      cur = i
    cur += cnt
  return ans

T = input()
for t in range(1, T + 1):
  print 'Case #%d: %d' % (t, solve())
