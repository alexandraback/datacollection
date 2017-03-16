#!/usr/bin/env python
import sys
from decimal import *
from itertools import combinations, product

def count_sqrts(a, b):
  """ count palindromes in [a,..,b] whose square is also a palindrome"""
  def check(l):
    n = int(''.join(map(str, l)))
    if a <= n <= b:
      s = str(n*n)
      if s == s[::-1]:
        #print ''.join(map(str, l))
        return 1
    return 0

  # the following observation is powerful enough to deal with the required input range:
  #   when multiplying two palindromes, one of the digits of the result is equal to the sum of squares
  # therefore:
  #   THE SUM OF SQUARES OF THE DIGITS OF THE HYPOTHETICAL SQUARE ROOT HAS TO BE <= 9
  # there are only a few options:
  count = 0
  min_digits = len(str(a))
  max_digits = len(str(b))

  #   1) the single-digit numbers
  if min_digits == 1:
    count += check([1])
    count += check([2])
    count += check([3])
    min_digits += 1

  for num_digits in range(min_digits, max_digits+1):
    first_half = range((num_digits+1)//2+1,num_digits)

    for initial_digit, mid, remaining_ones in [
        (2, [1], 0),    #   2) '2' at the beginning and end, at most one '1' in the midpoint
        (1, [1,2], 6/2)   #   3) '1' at the beginning and end, at most one '1' or '2' in the midpoint, and at most six '1's in the rest
      ]:
      midpoint_digits = [None] + mid if num_digits % 2 else [None]
      for d in midpoint_digits:
        for num_ones in range(remaining_ones+1):
          for indices in combinations(first_half, num_ones):
            l = [0] * num_digits
            l[0] = l[num_digits-1] = initial_digit
            if d is not None:
              l[num_digits//2] = d
            for i in indices:
              l[i-1] = l[num_digits-i] = 1
            count += check(l)

  return count


def count(A, B):
  """ count fair squares """
  # poor man's floor of the square root
  a = int(A.sqrt()) - 1
  while a*a < A:
    a += 1
  b = int(B.sqrt()) + 1
  while b*b > B:
    b -= 1
  return count_sqrts(a, b)


# process all tests
test_count = int(sys.stdin.readline())
for i in range(test_count):
  A, B = map(Decimal, sys.stdin.readline().strip().split())
  print 'Case #%d: %d' % (i+1, count(A, B))
