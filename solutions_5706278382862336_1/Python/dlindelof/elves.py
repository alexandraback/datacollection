#!/usr/bin/python

import math
import sys
import fractions

GENERATIONS = 40
ANCESTORS = 2**GENERATIONS

def solve(P, Q):
  pure_generations = 0
  gcd = fractions.gcd(P, Q)
  P = P / gcd
  Q = Q / gcd
  if ANCESTORS / float(Q) != ANCESTORS / Q:
    return "impossible"
  elves = P * ANCESTORS / Q
  while elves >= 2:
    pure_generations += 1
    elves /= 2.0
  return GENERATIONS - pure_generations

def main():
  N = int(sys.stdin.readline())
  for case in range(1, N + 1):
    [P, Q] = [int(x) for x in sys.stdin.readline().split("/")]
    print "Case #%d: %s" % (case, solve(P, Q))

if __name__ == "__main__":
  main()
 
