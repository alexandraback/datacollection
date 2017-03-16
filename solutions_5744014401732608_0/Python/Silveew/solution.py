import math
import numpy as np  # http://www.scipy.org/scipylib/download.html

def read_int(): return int(raw_input())
def read_pair_list(): return [(int(pair.split(',')[0]), int(pair.split(',')[1])) for pair in raw_input().split()]
def read_int_list(): return [int(x) for x in raw_input().split()]
def read_pair(): return [int(x) for x in raw_input().strip().split(',')]
def read_string(): return raw_input().strip()


def split(number, base):
    d = [];
    while number > 0:
        d.append(number % base);
        number /= base
    d.reverse()
    return d


def parse_input():
  T = read_int()
  cases = []
  for _ in xrange(T):
    cases.append(read_int_list())
  return cases

def max_poss(B):
  return 2**B


def nr_buildings_needed(M):
  return int(math.ceil(math.log(M, 2))) + 2


def solve_case(args):
  B, M = args
  nr_needed = nr_buildings_needed(M)
  if nr_needed > B:
    return 'IMPOSSIBLE'

  Mbits = []
  M = M - 1
  for _ in xrange(B-1):
    Mbits.append(M % 2)
    M = M / 2
  Mbits.reverse()
  Mbits.append(1)
  assert Mbits[0] == 0
  return Mbits




if __name__ == '__main__':
  for idx, args in enumerate(parse_input()):
    res = solve_case(args)
    if res == 'IMPOSSIBLE':
      print 'Case #%d:' % (idx + 1), res
    else:
      print 'Case #%d: POSSIBLE' % (idx + 1)
      print ''.join(map(str, res))
      nr_bits = len(res)
      for i in xrange(2, nr_bits+1):
        print ('0' * i) + ('1' * (nr_bits-i))
