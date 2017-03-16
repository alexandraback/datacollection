# -*- coding: utf-8 -*-

# Qualification Round 2016
# Problem D. Fractiles
# this algorism can apply only small input, not apply large one.

T = int(input())
dictize = lambda x: {"K": int(x[0]), "C": int(x[1]), "S": int(x[2])}
KCSs = list(map(dictize, [input().split(" ") for i in range(T)]))

for t in range(T):
  K = KCSs[t]["K"]
  C = KCSs[t]["C"]
  S = KCSs[t]["S"]

  c = 1
  a = list(range(0, S))
  while c < C:
    for s in range(0, S):
      a[s] = a[s] + (K ** c) * s
    c += 1

  print("Case #{}: {}".format(t + 1, " ".join(map(lambda x: str(x + 1), a))))

