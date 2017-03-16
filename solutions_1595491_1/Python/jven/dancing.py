"""
Google Code Jam, Qualification Round 2012
Problem 2
"""

__author__ = 'Justin Venezuela (jven@mit.edu)'

from sys import stdin
import os

def parse_input(data):
  test_cases = []
  for l in data[1:]:
    tokens = l.rstrip().split()
    test_cases.append([int(tokens[1]), int(tokens[2]), [int(e) for e in tokens[3:]]])
  return test_cases

def solve_test_case(test_case):
  surprises, best, scores = test_case
  can_have_best = [can_have_nonsurprising_best(score, best) for score in scores]
  for i in range(len(scores)):
    score = scores[i]
    if surprises > 0 and not can_have_best[i] and can_have_surprising_best(score, best):
      can_have_best[i] = True
      surprises -= 1
  ans = sum([1 for b in can_have_best if b])
  return ans

def can_have_nonsurprising_best(score, best):
  return score >= 3 * best - 2

def can_have_surprising_best(score, best):
  return score >= 2 and score <= 28 and score >= 3 * best - 4

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
  write_output(output, 'output-dancing.out')

if __name__ == '__main__':
  main()
