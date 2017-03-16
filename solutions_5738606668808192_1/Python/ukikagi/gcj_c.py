# coding: utf-8
import sys
import operator
from itertools import *
from random import choice
from sympy import prime

def read():
  return int(input())

def reads():
  return [int(s) for s in input().split()]

T = read()
(N, J) = reads()

print("Case #1:")

for _ in range(J):
  while True:
    s = "1" + "".join(choice(["0", "1"]) for i in range(N-2)) + "1"
    comp = [0] * 11
    for b in range(2, 11):
      n = int(s, b)
      for k in range(1, 101):
        if n % prime(k) == 0:
          comp[b] = prime(k)
          break
    if all(comp[b] > 0 for b in range(2, 11)):
      print(s + " " + " ".join(str(comp[b]) for b in range(2, 11)))
      break
