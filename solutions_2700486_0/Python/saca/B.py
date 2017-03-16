#!/usr/bin/env python3

from sys import stdin

class Responder:
  def __init__(self):
    self.answer_no = 1
  def write(self, answer):
    print("Case #{}: {}".format(self.answer_no, answer))
    self.answer_no += 1

#################################
# BRUTE
#################################

def locate(state):
  if not 0 in state:
    return set([(0,0)])
  
  if 1 in state and state[1] == state[0] + 1 and -1 in state and state[-1] == state[0] + 1:
    return set([(0,state[0] + 2)])

  locations = set()
  #rightward
  yr = 0
  xr = state[0] + 2
  while xr in state and state[xr] == yr and xr: 
    xr -= 1
    yr += 1
  if xr:
    locations.add((xr, yr))

  #leftward
  yl = 0
  xl = -state[0] - 2
  while xl in state and state[xl] == yl and xl:
    xl += 1
    yl += 1
  if xl:
    locations.add((xl, yl))

  return locations

def brute_solve():
  new, old = 1, 0
  states = [[], []]
  states[new].append(dict())

  for i in range(N):
    old, new = new, old
    states[new] = []
    for state in states[old]:
      locations = locate(state)
      for location in locations:
        d = dict(state)
        d[location[0]] = location[1]
        states[new].append(d)

  count = 0
  for state in states[new]:
    if X in state and state[X] >= Y:
      count += 1

  return float(count) / len(states[new])
  
if __name__ == "__main__":
  resp = Responder()
  for _ in range(int(stdin.readline())):
    N, X, Y = map(int, stdin.readline().split())
    resp.write(brute_solve())
