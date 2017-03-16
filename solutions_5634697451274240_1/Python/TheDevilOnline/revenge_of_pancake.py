#!/usr/bin/python
# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
  case = raw_input();
  
  current = '+'
  count = 0
  
  for j in xrange(0,len(case)):
    if case[len(case) - j - 1] != current:
      count += 1
      current = case[len(case) - j - 1]
  
  print "Case #{}: {}".format(i, count)
        