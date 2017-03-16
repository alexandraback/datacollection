import math
import sys

def solve(input_file):
  f = open(input_file, 'r')
  output_file = input_file.split('.')[0] + ".out"
  o = open(output_file, 'w')
  num_tests = int(f.readline())
  found = 0
  for nt in range(num_tests):
    o.write("Case #%d:\n" % (nt+1))
    [N,J] = map(int, f.readline().split(' '))
    print "Doing case %d with N: %d, J: %d\n" % (nt+1, N, J)
    current_num = 0
    for i in range(2 ** (N-2)):
      middle = '{:014b}'.format(i)
      real_number = '1' + middle + '1'
      print "Testing %s\n" % real_number
      divisors = []
      for j in range(2, 11):
        num_to_test = convert_to_base(real_number, j)
        print "with base %d, testing %d\n" % (j, num_to_test)
        divisor = find_smallest_divisor(num_to_test)
        if divisor != 1:
          divisors.append(divisor)
        else:
          break
      if len(divisors) == 9:
        o.write("%s %s\n" % (real_number, ' '.join(map(str, divisors))))
        found += 1
        if found == J:
          break
      else:
        continue

def find_smallest_divisor(number):
  number = int(number)
  if number % 2 == 0:
    return 2
  if number % 3 == 0:
    return 3
  current_divisor = 5
  stopping_point = math.sqrt(number)
  while current_divisor < stopping_point:
    if number % current_divisor == 0:
      return current_divisor
    if number % (current_divisor + 2) == 0:
      return current_divisor + 2
    current_divisor += 6
  return 1

def convert_to_base(number, base):
  s = map(int, list(str(number)[::-1]))
  answer = 0
  for i in range(len(s)):
    answer += s[i] * base ** i
  return answer

solve('C-small.in')