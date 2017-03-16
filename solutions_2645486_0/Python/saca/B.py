#!/usr/bin/env python3

from sys import stdin

class Responder:
  def __init__(self):
    self.answer_no = 1
  def write(self, answer):
    print("Case #{}: {}".format(self.answer_no, answer))
    self.answer_no += 1

def gain():
  best = [[v[0] * (E - e) for e in range(E + 1)], [0] * (E+1)]
  new, old = 0, 1
  for i in range(1,N):
    old, new = new, old
    for e in range(E + 1):
      best[new][e] = 0
      for prev in range(max(0, e-R), E+1):
        best[new][e] = max(best[new][e], best[old][prev] + v[i] * (min(E, prev+R) - e))

  return max(best[new])

if __name__ == "__main__":
  resp = Responder()
  for _ in range(int(stdin.readline())):
    E, R, N = map(int, stdin.readline().split())
    v = list(map(int, stdin.readline().split()))
    resp.write(gain())
