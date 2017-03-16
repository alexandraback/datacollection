#!/usr/bin/env python3

T = int(input())
for case in range(1, T+1):
  N = abs(int(input()))
  if N:
    res, s = 0, set()
    while len(s) < 10:
      res += N
      s.update(str(res))
  else:
    res = "INSOMNIA"
  print("Case #{}: {}".format(case, res))

