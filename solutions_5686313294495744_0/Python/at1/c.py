import sys

def solve():
  n = int(input())
  topics = []
  for i in range(n):
    topics.append(input().split())
  
  res = 0
  for m in range(1 << n):
    if (m % 1000 == 0):
      sys.stderr.write(str(m) + "\n")
    first = set()
    second = set()
    for i in range(n):
      if (m >> i) & 1:
        first.add(topics[i][0])
        second.add(topics[i][1])

    can = True
    cnt = 0
    for i, t in enumerate(topics):
      if not((m >> i) & 1):
        cnt += 1
        if t[0] not in first or t[1] not in second:
          can = False
          break
    if can:
      res = max(res, cnt)
  print(res)


T = int(input())
for t in range(1, T + 1):
  print("Case #" + str(t) + ": ", end='')
  solve()

