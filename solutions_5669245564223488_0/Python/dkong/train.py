import sys
import re
import scipy.misc as spm

def solve(cars):
  data = {}
  finished_letters = set()

  for char in "abcdefghijklmnopqrstuvwxyz":
    data[char] = {'first': False, 'middle': 0, 'last': False}

  for c in cars:
    for char in c:
      if char in finished_letters:
        return 0
    if re.match(r'^(\w)\1*$', c):
      # aaaaaaa
      char = c[0]
      data[char]['middle'] += 1
    elif re.match(r'^(\w)\1*(\w)\2*$', c):
      # aaabbb
      char = c[0]
      if data[char]['last']:
        return 0
      data[char]['last'] = c
      char = c[-1]
      if data[char]['first']:
        return 0
      data[char]['first'] = c
    else:
      first = c[0]
      last = c[-1]
      if data[first]['last'] or data[last]['first']:
        return 0
      data[first]['last'] = c
      data[last]['first'] = c
      i = 1
      j = len(c) - 2
      # Advance i to end of first and j to start of last.
      while c[i] == first:
          i += 1
      while c[j] == last:
          j -= 1
      while i <= j:
        char = c[i]
        if char in finished_letters or char == first or char == last:
          return 0
        finished_letters.add(char)
        while c[i] == char:
          i += 1

  # Consolidate data into letter trains.
  letters = set("abcdefghijklmnopqrstuvwxyz")
  num_trains = 0
  while len(letters) > 0:
    # Find letter with no 'first' attribute.
    next_char = False
    for char in letters:
      if data[char]['first']:
        continue
      next_char = char
    if not next_char:
      # Circular dependency?
      return 0
    letters.remove(next_char)
    if data[next_char]['middle'] == 0 and not data[next_char]['last']:
      continue
    num_trains += 1
    while data[next_char]['last']:
      next_char = data[next_char]['last'][-1]
      letters.remove(next_char)

  result = 1
  for char in data:
    result *= int(spm.factorial(data[char]['middle']))
  return (int(spm.factorial(num_trains)) * result) % 1000000007

sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

total_cases = int(raw_input())
for case_number in range(1, total_cases + 1):
  cars = []
  n = int(raw_input())
  cars.extend(raw_input().split(' '))
  result = solve(cars)
  print "Case #{}: {}".format(case_number, result)
