#!/usr/bin/python

import sys
import math

all_input = sys.stdin.readlines()

assert len(all_input) == 1 + int(all_input[0])

def Solve(p, q):
  if 2**40 * p % q != 0:
    return "impossible";
  res = 40 - math.log(2**40*p/q, 2);
  return int(math.ceil(res));

for case, problem in enumerate(all_input[1:]):
  p, q = map(int, problem.split('/'))
  print 'Case #%s: %s' % (case + 1, Solve(p, q))
