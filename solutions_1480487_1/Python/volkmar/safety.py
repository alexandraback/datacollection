#!/usr/bin/env python3

import sys

def process(input, output):
  nb = int(input.readline().rstrip())

  for val in range(1, nb+1):
    print("Case ",val)

    # reading data
    inputs = input.readline().rstrip().split()

    scores = inputs[1:]
    for i in range(len(scores)):
      scores[i] = int(scores[i])

    nbPerson = len(scores)
    total = sum(scores)

    sumNeg = 0
    nbPos = nbPerson

    answer = ""

    for i in range(len(scores)):
      value = (2/nbPerson) - scores[i]/total
      if value < 0:
        sumNeg += value
        nbPos -= 1
        scores[i] = -1

    for s in scores:
      if s == -1:
        value = 0
      else:
        value = round(100*((2/nbPerson) - s/total + sumNeg/nbPos), 6)

      answer += " " + str(value)

    output.write('Case #%d:%s\n' % (val,answer))

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
