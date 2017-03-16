#!/usr/bin/env python

import sys

N=int(sys.argv[1])
J=int(sys.argv[2])

#print "Bits = ", N
#print "Nr jamcoins = ", J
print "Case #1:"

def find_divisor(nr):
  c = 2
  p = False
  if (nr % 2 == 1):
    c = 3
    while (c*c <= nr) and ((nr % c) != 0):
      c = c + 2
    if ((c*c) > nr):
      p = True
  return c, p



found = 0
pattern = 2**(N-1) + 1
top_bit = 2**(N)
divisors = [0] * 11

while ((found < J) and (pattern < top_bit)):
  #print "Checking: ", pattern, " = ", pstr
  (divisors[2],prime) = find_divisor(pattern)
  if (not prime):
    pstr = ("{0:0"+str(N)+"b}").format(pattern)
    b = 3
    while (not prime) and (b < 11):
      candidate = int(pstr, base=b)
      #print "Canditate in base ", b, " is ", candidate
      (divisors[b],prime) = find_divisor(candidate)
      b = b+1
   
    if (not prime):
      found = found + 1
      print pstr + " " + (" ".join([str(d) for d in divisors[2:11]]))

  pattern += 2
    
