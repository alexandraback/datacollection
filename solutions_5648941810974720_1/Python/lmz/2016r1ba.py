import sys
import itertools
sys.setrecursionlimit(10000)

tc = int(sys.stdin.readline().strip())

for tmp_tc in xrange(tc):
  [ S ] = sys.stdin.readline().strip().split(' ')
  cnts = {}
  for d in xrange(26): cnts[chr(ord('A')+d)] = 0
  for s in S:
    cnts[s] = cnts[s] + 1
  digits = []

  while cnts['Z']:
    for s in 'ZERO':
      cnts[s] -= 1
    digits.append(0)

  while cnts['X']:
    for s in 'SIX':
      cnts[s] -= 1
    digits.append(6)

  while cnts['W']:
    for s in 'TWO':
      cnts[s] -= 1
    digits.append(2)

  while cnts['G']:
    for s in 'EIGHT':
      cnts[s] -= 1
    digits.append(8)

  while cnts['H']:
    for s in 'THREE':
      cnts[s] -= 1
    digits.append(3)

  while cnts['S']:
    for s in 'SEVEN':
      cnts[s] -= 1
    digits.append(7)

  while cnts['V']:
    for s in 'FIVE':
      cnts[s] -= 1
    digits.append(5)

  while cnts['F']:
    for s in 'FOUR':
      cnts[s] -= 1
    digits.append(4)

  while cnts['O']:
    for s in 'ONE':
      cnts[s] -= 1
    digits.append(1)

  while cnts['N']:
    for s in 'NINE':
      cnts[s] -= 1
    digits.append(9)

  digits.sort()
  res = ''.join([str(d) for d in digits])
  print "Case #%d: %s" % (1+tmp_tc, res)

