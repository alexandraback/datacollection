#!/usr/bin/env python3

T = int(input())
for case in range(1, T+1):
  N = int(input())
  L = [list(map(int, input().split())) for _ in range(2*N-1)]
  res = []
  while L:
    L.sort()
    if len(L) > 1 and L[0][0] == L[1][0]:
      res.append(sum(L[0]) + sum(L[1]) - sum(r[0] for r in L))
      L = [r[1:] for r in L[2:]]
    elif L:
      e = L[0][1:]
      i = [r[0] for r in L]
      while i:
        if len(e) > 0 and i[0] == e[0]:
          e = e[1:]
        else:
          res.append(i[0])
        i = i[1:]
      break
  print("Case #{}: {}".format(case, ' '.join(map(str, res))))

