
import itertools

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


def solve_case(args):
  return None


def solve_bf(args):
  J, P, S, K = args

  # check solution
  all_pairs_jp = { (j, p): K for j in xrange(J) for p in xrange(P)}
  all_pairs_js = { (j, s): K for j in xrange(J) for s in xrange(S)}
  all_pairs_ps = { (p, s): K for p in xrange(P) for s in xrange(S)}

  chosen_outfits = {}

  all_outfits = [(j, p, s) for j, p, s in itertools.product(range(J), range(P), range(S))]

  while True:
    best_outfit = None
    best_bottleneck = 0

    for outfit in all_outfits:
      j, p, s = outfit
      if outfit in chosen_outfits:
        continue
      b1 = all_pairs_jp[(j, p)]
      b2 = all_pairs_js[(j, s)]
      b3 = all_pairs_ps[(p, s)]
      b = min(b1, b2, b3)

      if b > best_bottleneck:
        best_bottleneck = b
        best_outfit = outfit

    if best_outfit is None:
      break

    bj, bp, bs = best_outfit
    all_pairs_jp[(bj, bp)] -= 1
    all_pairs_js[(bj, bs)] -= 1
    all_pairs_ps[(bp, bs)] -= 1
    chosen_outfits[best_outfit] = True

  return len(chosen_outfits), chosen_outfits.keys()


if __name__ == '__main__':
  for idx, args in enumerate(parse_input()):
    res, sol = solve_bf(args)
    print 'Case #%d:' % (idx + 1), res
    for s in sol:
      print ' '.join([str(x+1) for x in s])
