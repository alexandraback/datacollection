import operator
import sys

def calculate(Ps, B):
  # Case 3
  E = 1 + B + 1

  # Case 1 & 2
  Pcorrect = reduce(operator.mul, Ps, 1)
  for i in xrange(len(Ps) + 1):
    Ep = (B - len(Ps) + 2 * i + 1) + (B + 1) * (1 - Pcorrect)
    if Ep < E:
      E = Ep
    Pcorrect /= Ps[len(Ps)-i-1]

  return E

with open(sys.argv[1]) as fin:
  with open('output2', 'w') as fout:
    B = None
    for i, line in enumerate(fin):
      if i > 0:
        if i % 2 == 1:
          B = int(line.split()[1])
        else:
          Ps = map(float, line.split())
          fout.write('Case #%d: %.6f\n' % (i / 2, calculate(Ps, B)))
          B = None
