from functools import *
import math

def end(t,c):
  print('Case #' + str(t) + ': ', end='')
  print(c)

def idealEat(size):
  return (size*2 - 1)

def process(size, remaining):
  cost = 0
  alt_cost = len(remaining)
  if len(remaining) == 0:
    return 0
  if size == 1:
    return alt_cost
  target = remaining.pop()
  while size <= target:
    size = idealEat(size)
    cost += 1
  size += target
  cost += process(size,remaining)
  return min(cost,alt_cost)

 
testcases = int(input())
for tc in range(1, testcases + 1):
  a,n = [int(x) for x in input().split()]
  motes = [int(x) for x in input().split()]
  motes = list(reversed(sorted(motes)))
  ops = process(a, motes)
  end(tc,ops)
