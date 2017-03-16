import sys
import math
def isqrt(x):
    if x < 0:
        raise ValueError('square root not defined for negative numbers')
    n = int(x)
    if n == 0:
        return 0
    a, b = divmod(n.bit_length(), 2)
    x = 2**(a+b)
    while True:
        y = (x + n//x)//2
        if y >= x:
            return x
        x = y
T = int(raw_input())
for i in range(1, T+1):
  s = raw_input()
  temp = s.split()
  r = int(temp[0])
  t = int(temp[1])
  #print "r: ", r,"t: ",t,"\n"
  b = 2*r - 1
  #print "b: ", b
  #a = math.sqrt(b*b + 8*t)
  c = b*b+8*t
  #print "c: ", c
  a = isqrt(b*b+8*t)
  #print "a: ", a
  ans = math.floor((a - b)/4)
  #print "ans: ", ans
  print "Case #"+str(i)+":",int(ans)
