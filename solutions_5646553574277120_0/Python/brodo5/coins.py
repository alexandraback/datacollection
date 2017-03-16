import math
import itertools
import sys

FILENAME = 'C-small-attempt1'

def powerset(iterable):
  s = list(iterable)
  return itertools.chain.from_iterable(itertools.combinations(s, r) for r in range(len(s)+1))

def solve(c, denoms, v):
  for size in range(0, v):
    for combo in itertools.combinations(range(1, v + 1), size):
      new_denoms = denoms[:]
      new_denoms += combo
      new_denoms = set(new_denoms)
      need = []
      for i in range(0, v + 1):
        need.append(False)
      power = powerset(new_denoms)
      for p in power:
        if sum(p) <= v:
          need[sum(p)] = True
      good = True
      for i in range(len(need)):
        if not need[i]:
          good = False
          break
      if good:
        return size

f = open(FILENAME + '.in', 'r')
tests = int(f.readline())
sys.stdout = open(FILENAME + '.out', 'w')
for test in range(tests):
  c, d, v = map(int, f.readline().split())
  denoms = map(int, f.readline().split())
  out = solve(c, denoms, v)
  print 'Case #%d: %d' % (test + 1, out)
