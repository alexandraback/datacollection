# -*- coding: utf-8 -*-

# Qualification Round 2016
# Problem B. Revenge of the Pancakes

T = int(input())
Ss = [input() for i in range(T)]

for i in range(T):
  S = Ss[i]
  pm = S.count("+-")
  mp = S.count("-+")
  ans = pm + mp

  if (pm == mp) and (list(S)[0] == "-"):
    ans += 1
  elif (pm != mp) and (list(S)[0] == "+"):
    ans += 1

  print("Case #{}: {}".format(i + 1, ans))
