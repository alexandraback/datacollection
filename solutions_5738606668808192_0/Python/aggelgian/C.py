#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import itertools, math

def prep():
  print ("Case #1:")
  n, nums = 16, []
  nums = ["".join(num) for num in itertools.product('01', repeat=n) if num[0] != '0' and num[n-1] != '0']
  i, found, expected = 0, 0, 50
  while found < expected:
    sol = solve(nums[i])
    if sol != None:
      found += 1
      print ("{} {}".format(nums[i], sol))
    i += 1

def divisor(n):
  if n % 2 == 0 and n > 2:
    return 2
  for i in range(3, int(math.sqrt(n)) + 1, 2):
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
