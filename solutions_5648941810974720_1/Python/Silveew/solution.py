
def read_int(): return int(raw_input())
def read_pair_list(): return [(int(pair.split(',')[0]), int(pair.split(',')[1])) for pair in raw_input().split()]
def read_int_list(): return [int(x) for x in raw_input().split()]
def read_pair(): return [int(x) for x in raw_input().strip().split(',')]
def read_string(): return raw_input().strip()


def parse_input():
  T = read_int()
  cases = []
  for _ in xrange(T):
    cases.append(read_string())
  return cases


letters = 'ABCDEFGHIJLMNOPQRSTUVWXYZ'
def solve_case(word):
  lcounts = {c:0 for c in letters}
  for c in word:
    lcounts[c] += 1

  #print lcounts

  nzero = lcounts['Z']
  for c in 'ZERO':
    lcounts[c] -= nzero
  #print '0', nzero

  ntwo = lcounts['W']
  for c in 'TWO':
    lcounts[c] -= ntwo
  #print '2', ntwo

  nsix = lcounts['X']
  for c in 'SIX':
    lcounts[c] -= nsix
  #print '6', nsix

  neight = lcounts['G']
  for c in 'EIGHT':
    lcounts[c] -= neight
  #print '8', neight

  nseven = lcounts['S']
  for c in 'SEVEN':
    lcounts[c] -= nseven
  #print '7', nseven

  nfive = lcounts['V']
  for c in 'FIVE':
    lcounts[c] -= nfive
  #print '5', nfive

  nthree = lcounts['H']
  for c in 'THREE':
    lcounts[c] -= nthree
  #print '3', nthree


  nnine = lcounts['I']
  for c in 'NINE':
    lcounts[c] -= nnine
  #print '9', nnine

  nfour = lcounts['R']
  for c in 'FOUR':
    lcounts[c] -= nfour
  #print '4', nfour

  none = lcounts['N']
  for c in 'ONE':
    lcounts[c] -= none
  #print '1', none

  for c in letters:
    assert lcounts[c] == 0

  res = (
      ['0'] * nzero +
      ['1'] * none +
      ['2'] * ntwo +
      ['3'] * nthree +
      ['4'] * nfour +
      ['5'] * nfive +
      ['6'] * nsix +
      ['7'] * nseven +
      ['8'] * neight +
      ['9'] * nnine
  )
  return ''.join(res)


if __name__ == '__main__':
  for idx, args in enumerate(parse_input()):
    res = solve_case(args)
    print 'Case #%d:' % (idx + 1), res
