from functools import *
import math

def end(t,c):
  print('Case #' + str(t) + ': ', end='')
  print(c)

testcases = int(input())
for tc in range(1, testcases + 1):
  e,r,n = [int(x) for x in input().split()]
  v = [int(x) for x in input().split()]
  vm = []
  for i in range(n):
    m = 0
    for x in range(i+1,n):
      if v[x] > v[i]:
        m = x - i
        break
    vm.append(m)

  y = 0
  ce = e
  for ci,d in zip(v,vm):
    if d == 0:
      y += ce * ci
      ce = 0
    elif ce + r*d > e:
      overflow = ce + r*d - e
      min_use = min(ce, overflow)
      ce -= min_use
      y += min_use * ci
    ce += r

  end(tc,y)
