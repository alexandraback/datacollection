from fractions import Fraction
import math

def solve(fraction):
  p, q = fraction.numerator, fraction.denominator
  l2 = lambda x: math.log(x, 2)
  if int(l2(q)) != l2(q):
    return 0
  return int(math.ceil(l2(1) - l2(p) + l2(q)))

def rsolve(fraction):
  s = solve(fraction)
  if s > 40 or s <= 0:
    return 'impossible'
  else:
    return s

import fileinput
lines = [line.strip() for line in fileinput.input()]
assert(len(lines) == int(lines[0])+1)
for i, case in enumerate(lines[1:]):
  print 'Case #%d: %s' % (i+1, rsolve(Fraction(case)))
