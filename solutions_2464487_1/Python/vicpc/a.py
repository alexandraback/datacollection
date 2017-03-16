from math import *

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

T = input()


for i in range(T):
  #r, t = input()
  aux = raw_input()
  r = int(aux.split()[0])
  t = int(aux.split()[1])
  b = 2*r-1

  N = int(floor((-b + isqrt(b*b + 8*t))/4 ))
  print 'Case #'+ str(i+1)+': '+str(N)


