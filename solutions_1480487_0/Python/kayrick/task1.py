#!/usr/bin/env python

def solve(lst):
  N = 1.0 * int(lst[0])
  arr = map (lambda curr: int(curr), lst[1:])
  X = 1.0 * sum (arr)
  result = ""
  average = 2 * X / N
  new_arr = filter (lambda curr: curr <= average, arr)
  new_average = (sum (new_arr) + X) / len (new_arr)
  for item in arr:
    res = ((new_average - item) / X) * 100
    if res < 0:
      res = 0.0
    result += str(res) + " "
  return result[:-1]
    

num_of_cases = int(raw_input())

num = 1

while num <= num_of_cases:
  case = raw_input().split()
  print "Case #" + str(num) + ": " + str(solve(case))
  num += 1
