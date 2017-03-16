



def read_int(): return int(raw_input())
def read_pair_list(): return [(int(pair.split(',')[0]), int(pair.split(',')[1])) for pair in raw_input().split()]
def read_int_list(): return [int(x) for x in raw_input().split()]
def read_pair(): return [int(x) for x in raw_input().strip().split(',')]
def read_string(): return raw_input().strip()


def parse_input():
  T = read_int()
  cases = []
  for _ in xrange(T):
    cases.append(read_int_list())
  return cases


def combine(digits, base):
    number = 0
    for digit in digits:
        number *= base
        number += digit
    return number


def solve_case(K, C, S):
  if S * C < K:
    return 'IMPOSSIBLE'
  tile_ids = range(K)
  res = []
  while tile_ids:
    res.append(combine(tile_ids[:C], K))
    tile_ids = tile_ids[C:]
  assert len(res) <= S
  return ' '.join(map(lambda x: str(x+1), res))


if __name__ == '__main__':
  for idx, (K, C, S) in enumerate(parse_input()):
    res = solve_case(K, C, S)
    print 'Case #%d:' % (idx + 1), res
