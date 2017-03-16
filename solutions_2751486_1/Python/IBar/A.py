from functools import *
import math

def end(t,c):
  print('Case #' + str(t) + ': ', end='')
  print(c)

vowels = ['a', 'e', 'i', 'o', 'u']

def solve(name,n):
  subl = 0
  value = 0
  prevStart = -1
  ends = []
  for x in range(len(name)):
    if name[x] in vowels:
      subl = 0
    else:
      subl += 1
      if subl >= n:
        ends.append(x)
        start = x - n + 1
        pointsBefore = start - prevStart
        pointsAfter  = len(name) - x
        permsInside = pointsBefore * pointsAfter
        prevStart = start
        value += permsInside
  return value

testcases = int(input())
for tc in range(1, testcases + 1):
  name,n = [x for x in input().split()]
  n = int(n)
  prevStart = -1
  value = solve(name, n)
  end(tc,value)
