__author__ = 'pcjjman'
test_input = \
"""4
1
19
23
13"""
test_output = \
"""Case #1: Case #1: 1
Case #2: 19
Case #3: 15"""

import itertools
import math
test = False
line_number = 0

def get_input():
    global line_number
    if not test:
        return raw_input("")
    else:
        output = test_input.split("\n")[line_number]
        line_number += 1
        return output

#from https://stackoverflow.com/questions/13059540/reverse-a-numbers-order-and-palindrome
def reverse(num):
  rev = 0
  original_num = num
  while(num > 0):
    rev = (10*rev)+num%10
    num //= 10
  print "Original: {}, reversed: {}".format(original_num, rev)
  return rev

def reverse_check(num, target):
  rev = 0
  original_num = num
  while(num > 0):
    rev = (10*rev)+num%10
    num //= 10
  if rev > original_num and rev <= target:
      #print "REVERSING! Original: {}, Reversed: {}, Target: {}".format(original_num, rev, target)
      return rev - 1
  return original_num


case_number = 1

cases = []
number_of_cases = int(get_input())
for i in range(number_of_cases):
    cases.append(int(get_input()))
for case in cases:
    #greedy approach, move upward until we can flip the numbers
    count = 0
    i = 0
    while i < case:
        i += 1
        count += 1
        i = reverse_check(i, case)
    print "Case #{}: {}".format(case_number, count)
    case_number += 1
