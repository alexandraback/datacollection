#!/usr/bin/python

import sys

def solve(A, B, K):
  # Catalina owns any number less than K.
  # For her to win, random numbers must be such that no
  # bit is 1 for bits in positions greater than len(bin(K)).

  # 3 ^ shared length of A,B + 2 ^ overflow of max(A,B).
  # of course, discounting the number of 1's there are in K.

  bina = '{0:b}'.format(A)
  binb = '{0:b}'.format(B)
  bink = '{0:b}'.format(K)

  diff = abs(len(bina) - len(binb))
  shared = min(len(bina), len(binb)) - len(bink) + 1

  twos = pow(2, diff)
  threes = pow(3, shared)
  fours = pow(4, len(bink) - 1)

  return twos * threes * fours

def solve_naive(A, B, K):
  wins = 0
  for a in xrange(A):
    for b in xrange(B):
      if a & b < K:
        wins += 1
  return wins

def main():
  lines = iter(sys.stdin.readlines())
  cases = int(lines.next())
  for case in range(cases):
    [A, B, K] = map(int, lines.next().split())
    print 'Case #%d: %d' % (case+1, solve_naive(A, B, K))

main()
