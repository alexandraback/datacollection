from sys import stdin
from math import ceil

T = int(stdin.readline())

for _ in range(T):
  stdin.readline()
  v = map(int, stdin.readline().split())

  ans = 1000

  for i in range(1, 1001):
    s = 0
    for x in v:
      s += int(ceil(float(x) / i)) - 1
    ans = min(ans, s + i)

  print "Case #{}: {}".format(_ + 1, ans)
