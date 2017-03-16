from functools import *
import math

def end(t,c):
  print('Case #' + str(t) + ': ', end='')
  print(c)

def area(start,rings):
  rings = rings * 2
  rings += start
  ar = 0
  for x in range(start, rings, 2):
    ar -= x*x
  for x in range(start+1, rings+1, 2):
    ar += x*x
  return ar
 
testcases = int(input())
for tc in range(1, testcases + 1):
  r,t = [int(x) for x in input().split()]
  br = 1
  while (area(r,br) < t):
    br += 1

  if(area(r,br) > t):
    br -= 1

  end(tc,br)
