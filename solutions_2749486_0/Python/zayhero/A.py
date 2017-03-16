from collections import deque

dirt = [(0, -1), (0, 1), (1, 0), (-1, 0)]
r = ['S', 'N', 'E', 'W']

dp = {(0, 0): (0, 0)}
que = deque([(0, 0)])
while que:
  x, y = que.popleft()
  stp = dp[(x, y)][0] + 1
  for i in range(len(dirt)):
    d = dirt[i]
    xx = x + d[0] * stp
    yy = y + d[1] * stp
    if max(abs(xx), abs(yy)) > 500: continue
    if (xx, yy) in dp: continue
    dp[(xx, yy)] = (stp, i)
    que.append((xx, yy))

def cal(x, y):
  res = ''
  while x or y:
    stp, d = dp[(x, y)]
    res += r[d]
    x -= dirt[d][0] * stp
    y -= dirt[d][1] * stp
  return res[::-1]

def judge(res, x, y):
  p = 1
  xx, yy = 0, 0
  for elm in res:
    if elm == 'S': d = (0, -1)
    if elm == 'N': d = (0, 1)
    if elm == 'E': d = (1, 0)
    if elm == 'W': d = (-1, 0)
    xx += d[0] * p
    yy += d[1] * p
    p += 1
  assert (xx, yy) == (x, y)

T = int(raw_input(""))
for i in range(1, T + 1):
  x, y = (int(elm) for elm in raw_input("").split())
  res = cal(x, y)
  judge(res, x, y)
  print 'Case #%d: %s' % (i, res)