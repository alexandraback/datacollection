# coding: utf-8
import sys
import heapq
import bisect
import operator
from itertools import *

# def read():
#   return [int(s) for s in input().split()]

def read():
  return int(input())

def digits(n):
  while n > 0:
    yield n % 10
    n //= 10

T = read()

for t in range(1, T+1):
  N = read()

  if N == 0:
    print("Case #{0}: INSOMNIA".format(t))
    continue

  seen = [0] * 10

  for i in count(1):
    for d in digits(N * i):
      seen[d] = 1
    if all(seen):
      print("Case #{0}: {1}".format(t, N*i))
      break
