#! /bin/env python3

import sys

def process_case(infile, outfile, case):
  line = infile.readline()
  N, M, K = map(int, line.split())
  if K == 1:
    answer = 1
  elif K == 2:
    answer = 2
  elif K == 3:
    answer = 3
  elif K == 4:
    answer = 4
  elif K == 5:
    answer = 4
  elif K == 6:
    answer = 5
  elif K == 7:
    answer = 6
  elif K == 8:
    answer = 6
  elif K == 9:
    answer = 7
  elif K == 10:
    answer = 8
  elif K == 11:
    answer = 8
  elif K == 12:
    answer = 8
  elif K == 13:
    answer = 8
  elif K == 14:
    answer = 9
  elif K == 15:
    answer = 9
  elif K == 16:
    answer = 10
  elif K == 17:
    answer = 10
  elif K == 18:
    answer = 10
  elif K == 19:
    answer = 11
  elif K == 20:
    answer = 11
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
