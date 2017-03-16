#!/usr/bin/python

import fractions
import math
import sys

def solve(P, Q):
  [P, Q] = lowest(P, Q)
  limit = P * 1.0 / Q
  l = int(math.log(Q, 2))
  if P == 0 or pow(2, l) != Q:
    return 'impossible'
  k = 1
  quot = pow(0.5, k)
  while quot > limit:
    k += 1
    quot = pow(0.5, k)
    if k > 40:
      return 'impossible'
  return k

def lowest(P, Q):
  g = fractions.gcd(P, Q)
  return [P / g, Q / g]

def main():
  lines = iter(sys.stdin.readlines())
  cases = int(lines.next())
  for case in range(cases):
    [P, Q] = map(int, lines.next().replace('\n', '').split('/'))
    print 'Case #%d: %s' % (case+1, solve(P, Q))

main()
