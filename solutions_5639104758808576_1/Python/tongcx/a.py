import sys

T = int(sys.stdin.readline())

for _ in range(T):
  sm, v = sys.stdin.readline().split()
  cur_p = 0
  ans = 0
  for i, c in enumerate(v):
    if int(c) == 0:
      continue
    if cur_p >= i:
      cur_p += int(c)
    else:
      ans += i - cur_p
      cur_p = i + int(c)
  print "Case #{}: {}".format(_+1, ans)
