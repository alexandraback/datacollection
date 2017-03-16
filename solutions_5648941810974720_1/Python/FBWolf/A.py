import os
import math

digit_to_str = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"];
guess_order = [(0, 'Z'), (6, 'X'), (4, 'U'), (8, 'G'), (2, 'W'), (3, 'T'), (7, 'S'), (5, 'F'), (1, 'O'), (9, 'I')]

def solve(origin):
  total_letter_count = {}
  digit_count = {}
  for c in origin:
    if c not in total_letter_count:
      total_letter_count[c] = 1
    else:
      total_letter_count[c] += 1

  for guess_digit, guess_letter in guess_order:
    digit_count[guess_digit] = 0
    if guess_letter in total_letter_count and total_letter_count[guess_letter] > 0:
      digit_count[guess_digit] = total_letter_count[guess_letter]
      for c in digit_to_str[guess_digit]:
        total_letter_count[c] -= digit_count[guess_digit]

  res = ''
  for i in range(10):
    if digit_count[i] > 0:
      res += str(i) * digit_count[i]

  return res

fin = open('A-large.in', 'r')
fout = open('A.out', 'w')
for i, line in enumerate(fin):
  if i == 0:
    t = int(line)
    continue
  line = line.strip()

  res = solve(line)

  out_str = 'Case #%d: %s\n' % (i, res)
  print out_str
  fout.write(out_str)
fin.close()
fout.close()
