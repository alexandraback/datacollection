#!/usr/bin/env python3

from sys import stdin
from collections import defaultdict as dd

class Responder:
  def __init__(self):
    self.answer_no = 1
  def write(self, answer):
    print("Case #{}: {}".format(self.answer_no, answer))
    self.answer_no += 1

states = []

def solve():
  global A, motes, states
  motes.sort()
  states = [dd(int), dd(int)]
  old, new = 0, 1
  # state[idx, ops] = size
  states[new][0] = A
  shortcuts = set()

  for idx in range(0, len(motes)):
    new, old = old, new
    states[new] = dd(int)
    for ops in states[old]:
      size = states[old][ops]
      if size > motes[idx]:
        states[new][ops] = max(states[new][ops], size + motes[idx])
      elif size <= motes[idx]:
        # eat new particles
        if size != 1:
          tmp_size = size
          tmp_ops = 0
          while tmp_size <= motes[idx]:
            tmp_size += tmp_size - 1
            tmp_ops += 1
          states[new][ops+tmp_ops] = max(states[new][ops+tmp_ops], tmp_size + motes[idx])
            
        # eliminate next particle
        # states[new][ops+1] = max(states[new][ops+1], size)
        shortcuts.add(ops + len(motes) - idx)
  if len(shortcuts) and len(states[new]):
    return min(min(states[new].keys()), min(shortcuts))
  return min(shortcuts) if len(shortcuts) else min(states[new].keys())

if __name__ == "__main__":
  resp = Responder()
  for _ in range(int(stdin.readline())):
    A, _ = map(int, stdin.readline().split())
    motes = list(map(int, stdin.readline().split()))
    resp.write(solve())
