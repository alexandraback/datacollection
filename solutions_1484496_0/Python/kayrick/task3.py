#!/usr/bin/env python

def print_set(arr):
  result = ""
  for item in arr:
    result+= str(item) + " "
  print result[:-1]

def process(sum1, sum2, set1, set2, lst):
  if sum1 != 0 and sum1 == sum2:
    print_set (set1)
    print_set (set2)
    return True

  if len(lst) == 0:
    return False

  elem = lst[0]

  if sum1 > sum2:
    set1,set2 = set2, set1
    sum1,sum2 = sum2, sum1

  set1.append(elem)
  if process(sum1 + elem, sum2, set1, set2, lst[1:]):
    return True

  set1.pop()
  set2.append(elem)
  if process(sum1, sum2 + elem,set1, set2, lst[1:]):
    return True

  set2.pop()
  if process(sum1, sum2, set1, set2, lst[1:]):
    return True

  return False

def solve(lst):
  N = int(lst[0])
  nums = map(lambda curr: int(curr), lst[1:])
  nums.sort()
  process (0, 0, [], [], nums)
    

num_of_cases = int(raw_input())

num = 1

while num <= num_of_cases:
  case = raw_input().split()
  print "Case #" + str(num) + ":"
  solve(case)
  num += 1
