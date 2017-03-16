import math
import sys

def solve(r, t):
  i = 0
  ink_used = 0

  while True:
    next_ring = area(r + 2 * i + 1) - area(r + 2 * i)

    if ink_used + next_ring > t:
      break

    ink_used += next_ring
    i += 1

  return i

def fast_solve(r, t):
  # k * (2k + 2r - 1) = t
  k = int((math.sqrt(4 * r * r - 4 * r + 8 * t + 1) - 2 * r + 1) / 4)

  if k * (2 * k + 2 * r - 1) > t:
    k -= 1

  return max(1, k)

def area(radius):
  return radius * radius

def output(case, count):
  print('Case #{}: {}'.format(case, count))

if __name__ == '__main__':
  d = 'small'
  # d = 'large'

  num_tests = int(sys.stdin.readline())

  for i in range(num_tests):
    # [r, t] = [int(x) for x in sys.stdin.readline().split()]
    [r, t] = [float(x) for x in sys.stdin.readline().split()]
    # count = solve(r, t)
    count = fast_solve(r, t)
    output(i + 1, count)
