from reader import *

PROBLEM_LETTER = 'D'
PROBLEM_SIZE = 'large'

PROBLEM_PREFIX = PROBLEM_LETTER + '-' + PROBLEM_SIZE
INFILE = 'io/' + PROBLEM_PREFIX + '.in'
OUTFILE = 'io/' + PROBLEM_PREFIX + '.out'

# INFILE = 'io/test'
# OUTFILE = 'io/test.out'

def go():
  with open(INFILE, 'r') as fin, open(OUTFILE, 'w') as fout:
    T = readLineAsInt(fin)

    for i in range(T):
      K, C, S = readLineAsIntArr(fin)

      a = answer(K, C, S)
      if isinstance(a, list):
        ans_str = ' '.join(map(str,a))
      else:
        ans_str = '{}'.format(a)
      
      case_num = i + 1
      fout.write('Case #{}: {}\n'.format(case_num, ans_str))

def answer(k, c, s):
  # each student investigates c possible starting tiles
  if c*s < k:
    return 'IMPOSSIBLE'
  assert 1 <= k <= 100
  assert 1 <= c <= 100
  assert k**c <= 10**18

  powers = [k**(c-i-1) for i in range(c)]
  def index_of(tiles):
    assert len(tiles) == c
    total = 0
    for i in range(c):
      total += tiles[i] * powers[i]
    return total + 1

  students = []
  curr_tile = 0
  while curr_tile < k:
    tiles = []
    for i in range(c):
      tiles.append(curr_tile if curr_tile < k else 0)
      curr_tile += 1
    students.append(index_of(tiles))

  assert len(students) <= s
  return students

if __name__ == '__main__':
  pass
  go()