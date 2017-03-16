#!/usr/bin/python3

def solve():
  n = int(input())
  a = []
  for i in range(2 * n - 1):
    a.append(list(map(int, input().split())))
  cnt = {}
  for x in a:
    for y in x:
      if not y in cnt:
        cnt[y] = 0
      cnt[y] += 1
  res = []
  for x in cnt:
    if cnt[x] % 2 == 1:
      res.append(x)
  res.sort()
  return ' '.join(list(map(str, res)))

nt = int(input())
for tt in range(nt):
  print('Case #' + str(tt + 1) + ': ' + str(solve()))
