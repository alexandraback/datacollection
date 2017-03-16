"""
Google Code Jam, Round 1 2012
"""

__author__ = 'Justin Venezuela (jven@mit.edu)'

from sys import stdin
import os

def parse_input(data):
  cur_line = 0
  num_pwds = int(data[cur_line])
  pwds = [None] * num_pwds
  for i in range(num_pwds):
    cur_line += 1
    a, b = map(int, data[cur_line].split())
    cur_line += 1
    ps = map(float, data[cur_line].split())
    pwds[i] = (a, b, ps)
  return pwds

def solve_pwd(pwd):
  a, b, ps = pwd
  # Always try pressing enter first.
  best = b + 2
  for num_backspace in range(a + 1):
    prob_win = 1
    for i in range(a - num_backspace):
      prob_win *= ps[i]
    expected_keystrokes = (prob_win * (2 * num_backspace + b - a + 1) +
        (1 - prob_win) * (2 * num_backspace + b - a + 1 + b + 1))
    if expected_keystrokes < best:
      best = expected_keystrokes
  return '%.6f' % best

def get_output(pwds):
  output = ''
  for i in range(len(pwds)):
    pwd = pwds[i]
    ans = solve_pwd(pwd)
    output += 'Case #%d: %s\n' % (i + 1, ans)
  return output

def write_output(output, filename):
  if os.path.exists(filename):
    os.remove(filename)
  f = open(filename, 'a')
  f.write(output)
  f.close()

def main():
  data = stdin.readlines()
  maps = parse_input(data)
  output = get_output(maps)
  write_output(output, 'output.out')

if __name__ == '__main__':
  main()
