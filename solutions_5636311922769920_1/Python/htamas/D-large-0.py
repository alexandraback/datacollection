#!/usr/bin/env python3

T = int(input())
for case in range(1, T+1):
  K, C, S = map(int, input().split())
  if K > C*S:
    res = "IMPOSSIBLE"
  else:
    l = []
    for i in range(K):
      if i%C == 0:
        l.append(1)
      l[-1] += i*K**(i%C)
    res = ' '.join(map(str, l))
  print("Case #{}: {}".format(case, res))

