#!/usr/bin/env python3

import sys
import math

def isPalyndrome(x):
  s = str(x)
  size = len(s)

  for i in range(0, int(size/2)):
    if s[i] != s[size - i - 1]:
      return False

  return True

def process(input, output):
  nb = int(input.readline().rstrip())

  numbers = []

  for x in range(1, 10000000):
    if isPalyndrome(x) and isPalyndrome(x*x):
      numbers.append(x)

  print(len(numbers))

  for val in range(1, nb+1):
    minimum,maximum = input.readline().rstrip().split()
    minimum = math.ceil(math.sqrt(int(minimum)))
    maximum = math.floor(math.sqrt(int(maximum)))

    answer = 0

    for x in numbers:
      if x > maximum:
        break
      if x >= minimum:
        answer += 1

    output.write('Case #%d: %s\n' % (val,answer))

if __name__ == "__main__":
  if len(sys.argv) != 2:
    print("Need file as argument")
    sys.exit(1)

  input_file = sys.argv[1]

  # open the file
  input_handler = open(input_file, 'r')
  output_handler = open(input_file + '.out', 'w+')

  process(input_handler, output_handler)

  # close files
  input_handler.close()
  output_handler.close()
