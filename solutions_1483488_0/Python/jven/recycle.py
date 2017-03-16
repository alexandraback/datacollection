"""
Google Code Jam, Qualification Round 2012
Problem 3
"""

__author__ = 'Justin Venezuela (jven@mit.edu)'

from sys import stdin
import os

def parse_input(data):
  test_cases = []
  for l in data[1:]:
    t = l.rstrip().split()
    test_cases.append([int(t[0]), int(t[1])])
  return test_cases

def get_num_recycled_pairs(n, a, b):
  if n < a:
    return 0
  ans = 0
  s = str(n)
  ms = []
  for i in range(len(s)):
    m = int(s[i:] + s[:i])
    if m > n and m <= b and m not in ms:
      ans += 1
      ms.append(m)
  return ans

def solve_test_case(test_case):
  ans = 0
  a, b = test_case
  for n in range(a, b + 1):
    ans += get_num_recycled_pairs(n, a, b)
  return ans

def get_output(test_cases):
  output = ''
  for i in range(len(test_cases)):
    test_case = test_cases[i]
    output += 'Case #%d: %d\n' % (i + 1, solve_test_case(test_case))
  return output

def write_output(output, filename):
  if os.path.exists(filename):
    os.remove(filename)
  f = open(filename, 'a')
  f.write(output)
  f.close()

def main():
  test_cases = parse_input(stdin.readlines())
  output = get_output(test_cases)
  write_output(output, 'output-recycle.out')

if __name__ == '__main__':
  main()
