#!/usr/bin/env python

import string
import sys
import math

def allsame(n):
  if n < 10: return True

  last = n % 10
  n /= 10

  while n > 0:
    if n % 10 != last:
      return False
    n /= 10

  return True

def numdigits(n):
  return int(math.floor(math.log10(n))) + 1

def rots(n, bot, top, seen):
  if allsame(n) or n in seen:
    return 0

  digs = numdigits(n)

  seen.add(n)
  setsize = 1

  group = set([n])
  for b in range(1, digs):
    rot = (n % 10**b) * (10**(digs-b)) + (n / 10**b)
    if rot <= top and rot >= bot and numdigits(rot) == digs and rot not in group:
      group.add(rot)
      seen.add(rot)
      setsize += 1

  return setsize * (setsize-1) / 2

def findsets(low, high):
  seen = set()
  total = 0
  for i in range(low, high + 1):
    total += rots(i, low, high, seen)
  return total

def main():
  i = sys.stdin.readlines()
  for case in range(1, int(i[0]) + 1):
    (low, high) = map(int, i[case].strip().split(' '))
    print "Case #" + str(case) + ": " + str(findsets(low, high))

main()
