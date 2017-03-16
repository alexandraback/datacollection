#!/usr/bin/python

import math
import sys

def solve(P, Q):
  limit = P * 1.0 / Q
  if P == 0 or math.log(Q, 2) % 1 != 0:
    return 'impossible'
  k = 1
  quot = pow(0.5, k)
  while quot > limit:
    if k > 40:
      return 'impossible'
    k += 1
    quot = pow(0.5, k)
  return k

def main():
  lines = iter(sys.stdin.readlines())
  cases = int(lines.next())
  for case in range(cases):
    [P, Q] = map(int, lines.next().replace('\n', '').split('/'))
    print 'Case #%d: %s' % (case+1, solve(P, Q))

main()
