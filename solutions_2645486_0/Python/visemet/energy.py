import sys

def solve(e, E, R, v, i):
  if len(v) == i:
    return 0

  curr = -1

  # Iterate through all possible amounts of energy to spend on activity i
  for j in range(e + 1):
    value = j * v[i] + solve(min(E, e - j + R), E, R, v, i + 1)
    if curr == -1 or value > curr:
      curr = value

  return curr

def output(case, max_gain):
  print('Case #{}: {}'.format(case, max_gain))

if __name__ == '__main__':
  d = 'small'
  # d = 'large'

  num_tests = int(sys.stdin.readline())

  for i in range(num_tests):
    [E, R, N] = [int(x) for x in sys.stdin.readline().split()]
    v = [int(x) for x in sys.stdin.readline().split()]
    max_gain = solve(E, E, R, v, 0)
    output(i + 1, max_gain)
