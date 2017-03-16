from functools import *
import math

def end(t,c):
  print('Case #' + str(t) + ': ', end='')
  print(c)

vowels = ['a', 'e', 'i', 'o', 'u']

def solve(name,n):
  value = 0
  for x in range(len(name)):
    for y in range(x,len(name)):
      if subLength(name,x,y,n):
        value += 1
  return value

def subLength(name,i,j,n):
  subl = 0
  for x in range(i, j+1):
    if name[x] in vowels:
      subl = 0
    else:
      subl += 1
      if subl >= n:
        return True
  return False

testcases = int(input())
for tc in range(1, testcases + 1):
  name,n = [x for x in input().split()]
  n = int(n)
  value = solve(name, n)
  end(tc,value)
