import math
import itertools
from fractions import Fraction

class Hiker:

  def __init__(self, start, speed):
    self.start = start
    self.speed = speed

f = open("C-small-1-attempt1.in", "r")
tests = int(f.readline())
out = open("C-small.out", "w")
for t in range(tests):
  n = int(f.readline())
  hikers = []
  for i in range(n):
    d, h, m = map(int, f.readline().split())
    if h > 1:
      hikers.append(Hiker(d, m))
      hikers.append(Hiker(d, m + 1))
    else:
      hikers.append(Hiker(d, m))
  best = 0
  if hikers[0].start == hikers[1].start:
    if hikers[0].speed < hikers[1].speed:
      faster_hiker = hikers[0]
      slower_hiker = hikers[1]
    else:
      faster_hiker = hikers[1]
      slower_hiker = hikers[0]
  elif hikers[0].start < hikers[1].start:
    slower_hiker = hikers[0]
    faster_hiker = hikers[1]
  else:
    slower_hiker = hikers[1]
    faster_hiker = hikers[0]
  distance_to_start = 360 - slower_hiker.start
  time_it_takes_to_reach_start = Fraction(distance_to_start, 360) * slower_hiker.speed
  distance_traveled = Fraction(time_it_takes_to_reach_start, faster_hiker.speed) * 360
  print distance_to_start, time_it_takes_to_reach_start, distance_traveled
  if distance_traveled > 360 + distance_to_start:
    best = 1
  else:
    best = 0
  out.write("Case #{1}: {0}\n".format(best, t + 1))
