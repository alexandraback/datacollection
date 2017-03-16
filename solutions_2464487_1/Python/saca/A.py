#!/usr/bin/env python3

from sys import stdin
from math import log

class Responder:
  def __init__(self):
    self.answer_no = 1
  def write(self, answer):
    print("Case #{}: {}".format(self.answer_no, answer))
    self.answer_no += 1

def num_circles(r, t):
  step = 1 << (int)(log(t) / log(2) + 5)
  crt = 0
  while step > 0:
    num = crt + step
    if num * (2 * r + 2 * num - 1) <= t:
      crt += step
    step >>= 1
  return crt

if __name__ == "__main__":
  resp = Responder()
  for _ in range(int(stdin.readline())):
    resp.write(num_circles(*map(int, stdin.readline().split())))
