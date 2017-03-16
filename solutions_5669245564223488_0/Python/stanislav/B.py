import sys
from collections import OrderedDict

def is_valid(s):
  prev = s[0]
  unique = set()
  for ch in s:
    if ch != prev and ch in unique:
      return False
    prev = ch
    unique.add(ch)
  return True

def perm(ns, sets, prev, unique):
  if len(ns) == 0:
    return 1
  result = 0
  for n in ns:
    new_prev = prev
    new_unique = unique.copy()
    for ch in sets[n]:
      if ch != new_prev and new_prev != ' ' and ch in new_unique:
        return 0
      new_prev = ch
      new_unique.add(ch)
    ns.remove(n)
    result += perm(ns, sets, new_prev, new_unique)
    ns.add(n)
  return result

def run(t):
  N = int(raw_input())
  sets = raw_input().split()
  new_sets = []

  for s in sets:
    if not is_valid(s):
      print('Case #{}: {}'.format(t, 0))
      return
    new_sets.append(''.join(OrderedDict.fromkeys(s).keys()))

  result = perm(set(range(N)), new_sets, ' ', set())
  print('Case #{}: {}'.format(t, result))

T = int(raw_input())
for t in xrange(1, T + 1):
  run(t)
