import sys
import os
import math

def cal(n, r):
  return ((2 * r - 3) * n + 2 * n * (n + 1)) 

def solve():
  r, t = raw_input("").split()
  r, t = int(r), int(t)
  lt, rt = 1, 10 ** 18 + 5
  while lt < rt:
    md = (lt + rt) >> 1
    tot = cal(md, r)
    if tot > t: rt = md
    else: lt = md + 1
  return lt - 1

T = int(raw_input(""))

for i in range(1, T + 1):
  print "Case #%d: %d" % (i, solve())