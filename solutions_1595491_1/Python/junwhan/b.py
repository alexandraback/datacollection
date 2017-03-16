import math
import sys

def solve(ts, S, p):
  def triplet(t, surprising):
    if t in (0, 1):
      return (0, 0, t)

    if t % 3 == 0:
      basis, diff = t / 3, (1 if surprising else 0)
      return (basis - diff, basis, basis + diff)
    else:
      basis = int((math.floor if surprising else math.ceil)(t / 3.0))
      return (basis, basis, t - 2 * basis)

  num = 0

  for t in ts:
    nt, st = triplet(t, False), triplet(t, True)
    if max(nt) >= p:
      num += 1
    elif S > 0 and max(st) >= p:
      num += 1
      if min(st) + 2 == max(st):
        S -= 1

  return num

with open(sys.argv[1]) as fin:
  with open('output', 'w') as fout:
    for i, line in enumerate(fin):
      if i > 0:
        tokens = map(int, line.split())

        assert tokens[0] == len(tokens[3:])
        value = solve(tokens[3:], tokens[1], tokens[2])

        fout.write('Case #%d: %d\n' % (i, value))
