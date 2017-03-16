from operator import add
from bisect import bisect_left
from math import pi

#circle area: pi(R+1)^2 - piR^2 = pi(2R+1)
#next circle area: pi(2*(R+2)+1) = pi(2R+1+4); A_i = A_{i-1}+4*pi
#arithmetic progression: A0 = pi(2r+1), An = A_{n-1} + 4pi = A0 + 4*pi*n
#sum = (A0+An)/2*n = (pi(2r+1) + pi(2r+1) + 4*pi*n)/2*n = (pi(2r+1)+2*pi*n)*n

def area(n, r):
  return (n + 1) * ((2 * r + 1) + 2 * n)

T = int(raw_input())

for i in range(1, T + 1):
  r, t = map(int, raw_input().split())
  #print "area", area(0, r), area(1, r)
#binary search
  low = 0
  hig = 10 ** 10
  while low < hig:
    mid = (low + hig) / 2
    if area(mid, r) > t:
      hig = mid
    else:
      if low == mid: break
      low = mid
  print "Case #%d: %d" % (i, low + 1)    

