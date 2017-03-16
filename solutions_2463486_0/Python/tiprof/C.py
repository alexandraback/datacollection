#! /usr/bin/python

import sys,math


def recurse(n, avail, a, b, digits):
  rc = 0
  # first digit
  if digits & 1:
    rc = recurse_odd(n, avail, a, b, digits)
  else:
    rc = recurse_even(n, avail, a, b, digits)

  return rc

def recurse_even(n, avail, a, b, digits):
  if len(n)*2 == digits:
    p = int(n + n[-1:-len(n)-1:-1])
    if p < a or p > b:
      return 0
    #print p
    return 1

  rc = 0
  if n != "":
    # first digit cannot be 0
    rc += recurse_even(n + '0', avail, a, b, digits)
  if avail >= 2:
    rc += recurse_even(n + '1', avail - 2, a, b, digits)
  if avail >= 8:
    rc += recurse_even(n + '2', avail - 8, a, b, digits)

  return rc


def recurse_odd(n, avail, a, b, digits):
  if len(n)*2-1 == digits:
    p = int(n + n[-2:-len(n)-1:-1])
    if p < a or p > b:
      return 0
    #print p
    return 1

  rc = 0
  if n != "":
    # first digit cannot be 0
    rc += recurse_odd(n + '0', avail, a, b, digits)
  if len(n) < digits/2:
    if avail >= 2:
      rc += recurse_odd(n + '1', avail - 2, a, b, digits)
    if avail >= 8:
      rc += recurse_odd(n + '2', avail - 8, a, b, digits)
  else:
    if avail >= 1:
      rc += recurse_odd(n + '1', avail - 1, a, b, digits)
    if avail >= 4:
      rc += recurse_odd(n + '2', avail - 4, a, b, digits)
    if avail >= 9:
      rc += recurse_odd(n + '3', avail - 9, a, b, digits)

  return rc



def run():
  (A,B) = map(int, sys.stdin.readline().split())

  root_a = int(math.ceil(math.sqrt(A)))
  root_b = int(math.floor(math.sqrt(B)))

  str_root_a = "%d"%root_a
  digits_a = len(str_root_a)

  str_root_b = "%d"%root_b
  digits_b = len(str_root_b)

  rc = 0
  # build palindromes with sum(digit(p)**2) < 10
  for digits in range(digits_a, digits_b+1):
    rc += recurse("", 9, root_a, root_b, digits)

  return rc

cases = int(sys.stdin.readline())
for case in range(cases):
  print "Case #%d: %s"%(case+1, run())

