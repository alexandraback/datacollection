"""
Google Code Jam, Round 1 2012
"""

__author__ = 'Justin Venezuela (jven@mit.edu)'

from sys import stdin
import os

def parse_input(data):
  cur_line = 0
  num_cases = int(data[cur_line])
  cases = [None] * num_cases
  for i in range(num_cases):
    cur_line += 1
    num_levels = int(data[cur_line])
    levels = [None] * num_levels
    for j in range(num_levels):
      cur_line += 1
      one_star, two_star = map(int, data[cur_line].split())
      levels[j] = [one_star, two_star]
    cases[i] = levels
  return cases

def solve_case(case):
  levels = sorted(case, key=lambda level: -level[1])
  num_stars = 0
  num_plays = 0
  num_two_stars = 0
  still_playing = True
  while still_playing:
    still_playing = False
    # Check for 2-star play
    for level in levels:
      if num_stars >= level[1]:
        level[1] = 9999
        if level[0] < 9999:
          level[0] = 9999
          num_stars += 2
        else:
          num_stars += 1
        num_plays += 1
        num_two_stars += 1
        still_playing = True
        break
    # Check if we won.
    if num_two_stars >= len(levels):
      return str(num_plays)
    if still_playing:
      continue
    # Check for 1-star play
    for level in levels:
      if num_stars >= level[0]:
        level[0] = 9999
        num_stars += 1
        num_plays += 1
        still_playing = True
        break
    if still_playing:
      continue
    # No more plays possible, we lost.
    return 'Too Bad'

def get_output(cases):
  output = ''
  for i in range(len(cases)):
    case = cases[i]
    num_plays = solve_case(case) # Either an integer or 'Too bad.'
    output += 'Case #%d: %s\n' % (i + 1, num_plays)
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
