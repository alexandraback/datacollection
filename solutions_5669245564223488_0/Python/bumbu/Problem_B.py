import string
import math
import re
from fractions import Fraction

# _file = open("./test.txt")
_file = open("./B-small-attempt4.in")
# _file = open("./A-large.in")
_result = open("./result.txt", "w")

dataset_size = int(_file.readline())
case = 0

for i in range(dataset_size):
  case += 1
  combinations = 0
  multiplier = 1

  _file.readline() # cars

  cars = sorted(_file.readline().replace('\n', '').split(' '))

  # simplify strings
  for i in range(len(cars)):
    cars[i] = re.sub(r'(.)\1\1*', r'\1', cars[i])

  print cars

  # remove unisymbol duplicates
  for car in cars:
    if len(car) == 1 and cars.count(car) > 1:
      multiplier *= math.factorial(cars.count(car))
      for c in range(cars.count(car) - 1):
        del cars[cars.index(car)]

  # count letters except uniletters
  letters = {}
  lettersStart = {}
  lettersEnd = {}
  lettersMiddle = {}
  valid = True
  for car in cars:
    if len(car) > 1:
      # All letters except uniletters
      for letter in car:
        if letter in letters:
          letters[letter] += 1
        else:
          letters[letter] = 1

      # Letters start
      letter = car[0]
      if letter in lettersStart:
        lettersStart[letter] += 1
      else:
        lettersStart[letter] = 1

      # Letters end
      letter = car[len(car) -1]
      if letter in lettersEnd:
        lettersEnd[letter] += 1
      else:
        lettersEnd[letter] = 1

      # Middle
      if len(car) <= 2:
        middle = ''
      else:
        middle = car[1:-1]

      # First check if we allready do not have middles
      for m in middle:
        if m in lettersMiddle or m in lettersStart or m in lettersEnd:
          valid = False
          break

      # Check if start and end are different
      if middle:
        if car[0] == car[-1:]:
          valid = False
      # Add middle letters
      for m in middle:
        if m in lettersMiddle:
          lettersMiddle[m] += 1
        else:
          lettersMiddle[m] = 1
  # print letters
  # print lettersStart
  # print lettersEnd
  # print lettersMiddle

  # check if it is possible to form a valid train
  if valid:
    for car in cars:
      # Check if there is only one start and end
      if len(car) > 1:
        if car[0] in lettersEnd and lettersEnd[car[0]] > 1 or lettersStart[car[0]] != 1:
          valid = False
          break
        if car[-1:] in lettersStart and lettersStart[car[-1:]] > 1 or lettersEnd[car[-1:]] != 1:
          valid = False
          break

  print cars

  if valid:
    # create groups
    print lettersStart, lettersEnd
    for c in range(len(cars) - 1, 0, -1):
      car = cars[c]
      # print c, car
      if len(car) == 1:
        if car[0] in lettersEnd:
          # Append car
          for a in range(c):
            if cars[a][-1:] == car[0]:
              cars[a] += car
              del cars[c]
              break
        elif car[-1:] in lettersStart:
          # Prepend car
          for a in range(c):
            if cars[a][0] == car[-1:]:
              cars[a] = car + cars[a]
              del cars[c]
              break
      else:
        if car[0] in lettersEnd or car[0] in cars:
          # Append car
          for a in range(c):
            if cars[a][-1:] == car[0]:
              cars[a] += car
              del cars[c]
              break
        elif car[-1:] in lettersStart or car[-1:] in cars:
          # Prepend car
          for a in range(c):
            if cars[a][0] == car[-1:]:
              cars[a] = car + cars[a]
              del cars[c]
              break

    print cars
    multiplier *= math.factorial(len(cars))

  # print valid, multiplier, cars

  if not valid:
    combinations = 0
  else:
    combinations = multiplier % 1000000007
  result = "Case #" + str(case) + ": " + str(combinations)

  print result
  _result.write(result + "\n")

_file.close()
_result.close()
