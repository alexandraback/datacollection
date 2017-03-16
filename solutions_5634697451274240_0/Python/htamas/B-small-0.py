#!/usr/bin/env python3

T = int(input())
for case in range(1, T+1):
  S = input() + '+'
  print("Case #{}: {}".format(case, sum(S[i]!=S[i+1] for i in range(len(S)-1))))

