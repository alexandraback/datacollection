#!/usr/bin/python

import sys


def case(K, C, S):
  if S < K-1:
    return 'IMPOSSIBLE'

  # Consider all cases with just 1 gold tile in the original sequence:
  # The very first K tiles in the composition C will be:
  #   - GG..GG if the gold tile is in the first position
  #   - LX..XX for every other cases

  # So it wont be valuable to check tile 1. The other cases will look like:
  #   - LL..G..L
  #   - L.....LG
  #
  # We need to pick a tile from position 2 to position K to be able to avoid
  # missing two Ls.

  return ' '.join(map(lambda x: '%d'%x, range(2,K+1)))

f = open(sys.argv[1])
T = int(f.readline())
for i in xrange(T):
  (K, C, S) = map(int, f.readline().split())
  print "Case #%d: %s"%(i+1, case(K, C, S))

