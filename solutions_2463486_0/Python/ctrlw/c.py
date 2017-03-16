#!/usr/bin/python
import sys, math, re, bisect

def is_palindrome(s):
  if len(s) == 1:
    return True
    
  l = 0
  r = len(s) - 1
  while (r > l):
    if s[l] != s[r]:
      return False
    l += 1
    r -= 1
  return True
    
max_n = 3
max_square = 9
fair_squares = [1,4,9]
    
T = int(sys.stdin.readline())
for t in range(T):
  (A, B) = map(int, sys.stdin.readline().strip().split())
  # calculate missing squares and fair squares
  while max_square < B:
    max_n += 1
    if is_palindrome(str(max_n)):
      max_square = max_n * max_n
      if is_palindrome(str(max_square)):
        fair_squares += [max_square]
  
    
  # get the number of fair squares
  count = 0
  index = bisect.bisect_left(fair_squares, A)
  if index < len(fair_squares) and fair_squares[index] < A:
    index += 1
  while index < len(fair_squares) and fair_squares[index] <= B:
    count += 1
    index += 1

  print "Case #%d: %d" % (t + 1, count)

  
#print max_n, fair_squares