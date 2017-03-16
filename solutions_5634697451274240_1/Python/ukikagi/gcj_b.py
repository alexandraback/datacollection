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
  S = input() + "+"
  count = 0
  for i in range(1, len(S)):
    count += int(S[i-1] != S[i])
  print("Case #{0}: {1}".format(t, count))
