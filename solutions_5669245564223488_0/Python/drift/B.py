#! /bin/env python3

import sys

def is_valid(s):
  prev = None
  seen = set()
  for c in s:
    if prev is None:
      prev = c
      continue
    if c == prev:
      continue
    if c in seen:
      return False
    seen.add(prev)
    prev = c
  return True

def count_combinations(initial, cars):
  #print("initial: {}, cars: {}".format(initial, cars))
  if len(cars) == 0:
    return 1
  count = 0
  for i in range(len(cars)):
    car = cars[i]
    remaining = cars[:i] + cars[i+1:]
    appended = initial + car
    if is_valid(appended):
      count += count_combinations(appended, remaining)
  return count

def process_case(infile, outfile, case):
  infile.readline()
  line = infile.readline()
  cars = line.split()
  answer = count_combinations("", cars)
  outfile.write("Case #{}: {}\n".format(case, answer))

def main():
  input_file_name = sys.argv[1]
  output_file_name = sys.argv[2]

  with open(input_file_name, 'r') as infile:
    with open(output_file_name, 'w') as outfile:
      T = int(infile.readline())
      for case in range(1, T+1):
        process_case(infile, outfile, case)

main()
