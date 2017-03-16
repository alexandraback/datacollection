# -*- coding: utf-8 -*-

# Round 1B 2016
# Problem A.

from collections import defaultdict
alphabet = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]

T = int(input())

def calc(s):
  string = list(s)
  dd = defaultdict(int)
  for e in string:
    dd[e] += 1

  n0 = dd["Z"]
  n2 = dd["W"]
  n4 = dd["U"]
  n6 = dd["X"]
  n8 = dd["G"]
  n3 = dd["R"] - n4 - n0
  n5 = dd["F"] - n4
  n7 = dd["V"] - n5
  n9 = dd["I"] - n5 - n6 - n8
  n1 = dd["N"] - n7 - 2 * n9

  ans = "0" * n0 + "1" * n1 + "2" * n2 + "3" * n3 + "4" * n4 + "5" * n5 + "6" * n6 + "7" * n7 + "8" * n8 + "9" * n9
  return ans

for i in range(T):
  testcase = input()
  a = calc(testcase)
  print("Case #{}: {}".format(i + 1, a))