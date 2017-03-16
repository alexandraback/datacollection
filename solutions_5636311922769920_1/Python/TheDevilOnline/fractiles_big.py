#!/usr/bin/python

# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
  k, c, s = [int(s) for s in raw_input().split(" ")]  # read a list of integers, 2 in this case
  
  start = 2
  if (c == 1 and k != s) or s < k - 1:
    list = "IMPOSSIBLE"
  else:
    if k == 1 or k == s:
      start = 1
    list = ""
    for j in xrange(start, k + 1):
      if j > start:
        list += " "
      list += str(j)
  print "Case #{}: {}".format(i, list)
  # check out .format's specification for more formatting options