from sys import stdin

tc = int(stdin.readline())

for i in range(1, tc+1):
  r, t = map(int, stdin.readline().split())
  req = 0
  cnt = 0

  while req <= t:
    inner = r * r
    outer = (r+1) * (r+1)
    vol = outer - inner

    req += vol
    if req <= t:
      cnt += 1

    r = r + 2

  print 'Case #%d: %d' % (i, cnt)

