from reader import *

PROBLEM_LETTER = 'C'
PROBLEM_SIZE = 'small'

PROBLEM_PREFIX = PROBLEM_LETTER + '-' + PROBLEM_SIZE
INFILE = 'io/' + PROBLEM_PREFIX + '.in'
OUTFILE = 'io/' + PROBLEM_PREFIX + '.out'

# INFILE = 'io/test'
# OUTFILE = 'io/test.out'

def go():
  with open(INFILE, 'r') as fin, open(OUTFILE, 'w') as fout:
    T = readLineAsInt(fin)

    for i in range(T):
      N, J = readLineAsIntArr(fin)
      print(N)
      print(J)

      a = answer(N,J)
      # ans_str = '{}'.format(a)
      
      case_num = i + 1
      fout.write('Case #{}:\n'.format(case_num))
      for line in a:
        fout.write(line)
        fout.write('\n')

BASES = [2, 3, 4, 5, 6, 7, 8, 9, 10]

def answer(n, j):
  lines = []
  for coin, factors in produce(n,j):
    line = coin + ' ' + ' '.join(map(str,factors))
    lines.append(line)
  return lines

# coin: string of jamcoin
# divisors: array of verifying divisors
def verify(coin, divisors):
  assert len(divisors) == len(BASES)

  for base, divisor in zip(BASES, divisors):
    num = int(coin, base)
    assert divisor > 1
    assert divisor < num
    if num % divisor != 0:
      return False

  return True

def produce(n, limit):
  assert n % 2 == 0
  assert n >= 16
  half = n // 2
  k = half - 2
  assert 2**k >= limit
  format_str = '{0:0' + str(k) + 'b}'
  factors = [1+b**half for b in BASES]
  # print(factors)
  for i in range(limit):
    s = format_str.format(i)
    part = '1' + s + '1'
    coin = part + part
    assert verify(coin,factors)
    yield (coin, factors)


if __name__ == '__main__':
  pass
  go()
  # for coin, factors in produce(16, 50):
  #   print(coin)

  # for coin, factors in produce(32, 500):
  #   print(coin)
  # print(verify('100011', [5,13,147,31,43,1121,73,77,629]))