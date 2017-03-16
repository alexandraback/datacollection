# coding: utf-8
import sys
import heapq
import bisect
import operator
from itertools import *

def read():
  return int(input())

def reads():
  return [int(s) for s in input().split()]

T = read()

for t in range(1, T+1):
  # K進数
  (K, C, S) = reads()

  P = (K + C - 1) // C
  print("Case #{0}: ".format(t), end="")

  if P > S:
    print("IMPOSSIBLE")
    continue

  print(" ".join(str(sum(K**i * min(C*p+i, K-1) for i in range(C)) + 1) for p in range(P)))
