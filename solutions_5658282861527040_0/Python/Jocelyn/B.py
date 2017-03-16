#! /usr/bin/python

import sys

def solve(a, b, k):
  num_match = 0
  for i in xrange(a):
    for j in xrange(b):
      res = i & j
      if res < k:
        num_match += 1

  return num_match
      
fd = open(sys.argv[1])

num_cases = int(fd.readline())

for i in range(0, num_cases):
  (a, b, k) = [int(x) for x in fd.readline().strip().split(" ")]
  output = solve(a, b, k)
  print "Case #%d:" % (i+1), output

