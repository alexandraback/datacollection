#!/usr/bin/python

# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
  n = int(raw_input())  # read a list of integers, 2 in this case
  
  result = "INSOMNIA";
  found = 0;
  value = 0;
  if n > 0:
    while value < 10000000 and found < 1023:
      value += n
      string = str(value)
      #print value
      for j in xrange(0,len(string)):
        found = found | (1 << int(string[j]))
        #print "{0:10b}".format(found)
        #print found
  if(found == 1023):
    result = value    
  print "Case #{}: {}".format(i, result)
  # check out .format's specification for more formatting options