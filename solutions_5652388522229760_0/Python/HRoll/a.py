from reader import *

PROBLEM_LETTER = 'A'
PROBLEM_SIZE = 's0'

PROBLEM_PREFIX = PROBLEM_LETTER + '-' + PROBLEM_SIZE
INFILE = 'io/' + PROBLEM_PREFIX + '.in'
OUTFILE = 'io/' + PROBLEM_PREFIX + '.out'

# INFILE = 'io/A-s0.in'
# OUTFILE = 'io/A-s0.out'

def go():
  with open(INFILE, 'r') as fin, open(OUTFILE, 'w') as fout:
    T = readLineAsInt(fin)

    for i in range(T):
      N = readLineAsInt(fin)

      a = answer(N)
      ans_str = '{}'.format(a)
      
      case_num = i + 1
      fout.write('Case #{}: {}\n'.format(case_num, ans_str))

def answer(n):
  if n == 0:
    return 'INSOMNIA'
  seen = set()
  i = 1
  while len(seen) < 10:
    num = i*n
    i += 1
    seen |= set(str(num))
  return num

if __name__ == '__main__':
  pass
  go()