import random
import time


def read_int(): return int(raw_input())


def split(number, base):
    d = [];
    while number > 0:
        d.append(number % base);
        number /= base
    d.reverse()
    return d


def split_digits(number):
    return split(number, 10)


def parse_input():
  T = read_int()
  Ns = [read_int() for _ in xrange(T)]
  return {
    'T': T,
    'Ns': Ns,
  }


def all_true(flags):
  for f in flags:
    if not f:
      return False
  return True


def solve_case(N):
  if N == 0:
    return 'INSOMNIA'
  else:
    digits_seen = [False] * 10
    iN = N
    def remember_digits(iN):
      digits = split_digits(iN)
      for d in digits:
        digits_seen[d] = True
    remember_digits(iN)
    while not all_true(digits_seen):
      iN += N
      remember_digits(iN)
    return iN


def main():
  inputs = parse_input()
  for idx, N in enumerate(inputs['Ns']):
    print 'Case #%d: %s' % (idx+1, str(solve_case(N)))

if __name__ == '__main__':
  main()