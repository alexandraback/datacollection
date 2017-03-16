from reader import *

PROBLEM_LETTER = 'B'
PROBLEM_SIZE = 's0'

PROBLEM_PREFIX = PROBLEM_LETTER + '-' + PROBLEM_SIZE
INFILE = 'io/' + PROBLEM_PREFIX + '.in'
OUTFILE = 'io/' + PROBLEM_PREFIX + '.out'

# INFILE = 'io/test'
# OUTFILE = 'io/test.out'

def go():
  with open(INFILE, 'r') as fin, open(OUTFILE, 'w') as fout:
    T = readLineAsInt(fin)

    for i in range(T):
      pancakes = readLineAsStr(fin)

      a = answer(pancakes)
      ans_str = '{}'.format(a)
      
      case_num = i + 1
      fout.write('Case #{}: {}\n'.format(case_num, ans_str))

def answer(pancakes):
  ans = 0
  for i in range(len(pancakes) - 1):
    if pancakes[i] != pancakes[i+1]:
      ans += 1
  if pancakes[-1] == '-':
    ans += 1

  return ans

if __name__ == '__main__':
  pass
  go()