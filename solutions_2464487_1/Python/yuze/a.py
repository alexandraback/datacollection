#!/usr/bin/env python2.7
from decimal import *
import math
import sys

T = int(sys.stdin.readline())
getcontext().prec = 2000

for i in range(T):
  r, t = map(int, sys.stdin.readline().strip().split())
  result = (Decimal((2 * r - 1) ** 2 + 8 * t).sqrt() + (-2 * r + 1)) / 4
  print("Case #%d: %d" % (i + 1, int(result)))
