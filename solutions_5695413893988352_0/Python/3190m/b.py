# -*- coding: utf-8 -*-

# Round 1B 2016
# Problem B.

from functools import reduce
import re

T = int(input())

def calc(c, j):

  ptn_c = c.replace("?", "[0-9]")
  ptn_j = j.replace("?", "[0-9]")

  fm = "{0:0" + str(len(c)) + "d}"

  cand_all = [fm.format(i) for i in range(10 ** len(c))]
  cand_c = list(filter(lambda x: re.fullmatch(ptn_c, x, 0) != None, cand_all))
  cand_j = list(filter(lambda x: re.fullmatch(ptn_j, x, 0) != None, cand_all))

  cand_combi = []
  min_diff = 999

  for cc in cand_c:
    for jj in cand_j:
      diff = abs(int(cc) - int(jj))
      if min_diff == diff:
        cand_combi.append([cc, jj])
      elif min_diff > diff:
        cand_combi = [[cc, jj]]
        min_diff = diff

  a = cand_combi[0]
  for combi in cand_combi:
    if a[0] == combi[0] and a[1] > combi[1]:
      a = combi
    elif a[0] > combi[0]:
      a = combi

  return " ".join(a)

for i in range(T):
  c, j = input().split(" ")
  a = calc(c, j)
  print("Case #{}: {}".format(i + 1, a))