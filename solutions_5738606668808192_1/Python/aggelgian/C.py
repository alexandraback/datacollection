#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import itertools, math

def prep():
  print ("Case #1:")
  n, nums = 16, []
  nums = ["1" + (15 * "0") + "".join(num) for num in itertools.product('01', repeat=n) if num[n-1] != '0']
  i, found, expected = 0, 0, 500
  while found < expected:
    sol = solve(nums[i])
    if sol != None:
      found += 1
      print ("{} {}".format(nums[i], sol))
    i += 1

def divisor(n):
  if n % 2 == 0 and n > 2:
    return 2
  for i in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]:
    if n % i == 0:
      return i
  return None

def solve(num):
  divs = []
  for b in range(2, 11):
    d = divisor(int(num, b))
    if d == None:
      return None
    divs.append(str(d))
  return " ".join(divs)

if __name__=="__main__":
  prep()
