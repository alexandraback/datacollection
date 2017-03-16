#!/usr/bin/env python
from collections import namedtuple
from heapq import heappush, heappop
import sys


class Wall:
  def __init__(self):
    self.west = 0
    self.heights = []

  def is_attack_successful(self, w, e, s):
    assert s > 0
    for k in range(w, e):
      idx = k - self.west
      if idx < 0 or idx >= len(self.heights) or self.heights[idx] < s:
        return True

  def adjust(self, tribes):
    for t in tribes:
      w, e, s = t.w, t.e, t.s
      if w < self.west:
        self.heights = [0] * (self.west - w) + self.heights
        self.west = w
      if e - self.west > len(self.heights):
        self.heights = self.heights + [0] * (e - self.west - len(self.heights))

      for k in range(w, e):
        idx = k - self.west
        if self.heights[idx] < s:
          self.heights[idx] = s

Tribe = namedtuple('Tribe', ['d', 'n', 'w', 'e', 's', 'delta_d', 'delta_p', 'delta_s'])


def read_test(stdin):
  tribes = []
  N = int(stdin.readline())
  for i in range(N):
    line = map(int, stdin.readline().strip().split())
    tribes.append(Tribe(*line))
  return tribes


def count(tribes):
  # push all tribes onto heap
  pq = []
  for tribe in tribes:
    heappush(pq, tribe)

  # process next tribe(s)
  wall = Wall()
  successes = 0
  while pq:
    tribe = heappop(pq)
    day = tribe.d

    successful_tribes = []
    while True:
      # attack
      if wall.is_attack_successful(tribe.w, tribe.e, tribe.s):
        successes += 1
        successful_tribes.append(tribe)

      # schedule next attack
      if tribe.n > 1:
        heappush(pq, tribe._replace(
          d=tribe.d + tribe.delta_d,
          n=tribe.n - 1,
          w=tribe.w + tribe.delta_p,
          e=tribe.e + tribe.delta_p,
          s=tribe.s + tribe.delta_s))

      if not pq or pq[0].d > day:
        break
      tribe = heappop(pq)

    # adjust wall
    wall.adjust(successful_tribes)

  return successes


# process all tests
T = int(sys.stdin.readline())
for i in range(T):
  tribes = read_test(sys.stdin)
  print 'Case #%d: %d' % (i + 1, count(tribes))
