# -*- coding: utf-8 -*-

# Qualification Round 2016
# Problem A. Counting Sheep

T = int(input())
Ns = [int(input()) for i in range(T)]

for i in range(T):
  N = Ns[i]

  c = 1
  are_called = [False, False, False, False, False, False, False, False, False, False]

  while c < 100:
    m = list(str(N * c))
    for j in range(10):
      if str(j) in list(str(N * c)):
        are_called[j] = True

    if False in are_called:
      c += 1
    else:
      ans = N * c
      break
  else:
    ans = "INSOMNIA"

  print("Case #{}: {}".format(i + 1, ans))
