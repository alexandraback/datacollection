from functools import *
import math

def end(t):
  print('Case #' + str(t) + ': ', end='')

def north():
  print('SN', end='')
def south():
  print('NS', end='')
def east():
  print('WE', end='')
def west():
  print('EW', end='')

testcases = int(input())
for tc in range(1, testcases + 1):
  x,y = [int(x) for x in input().split()]
  end(tc)
  if x > 0:
    for i in range(x):
      east()
  else:
    for i in range(x * -1):
      west()
  if y > 0:
    for i in range(y):
      north()
  else:
    for i in range(y * -1):
      south()
  print()
