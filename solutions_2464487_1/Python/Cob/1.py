import math
cases = int(raw_input())
for caseno in range(1, cases + 1):
   (r, t) = map(int, raw_input().split())
   # the nth circle, starts from 0
   def sn(n):
      return (n + 1) * (2 * n + 2 * r + 1) 
   low = 1
   high = 10**18
   while high > low + 1:
   		m = (low + high) / 2
   		if sn(m) <= t:
   			low = m
   		else:
   			high = m

   if( sn (low) > t):
      low -= 1

   print "Case #%d: %d" % (caseno, low + 1)
    
    
