#! /bin/env python3

import sys
from math import log, ceil

def gcd(a, b):
  if b == 0:
    return a
  elif a > b:
    return gcd(b, a % b)
  else:
    return gcd(a, b % a)

def process_case(infile, outfile, case):
  fraction = infile.readline()
  P, Q = map(int, fraction.split("/"))
  divisor = gcd(P, Q)
  P = P // divisor
  Q = Q // divisor
  power = round(log(Q, 2))
  if pow(2, power) != Q:
    answer = "impossible"
  else:
    answer = ceil(log(Q / P, 2))
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
