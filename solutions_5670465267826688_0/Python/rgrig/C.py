#!/usr/bin/env python3

import sys

def one():
  return 1

def is_minus_one(x):
  return x == -1

mul_table =\
  [ [ 1, 2, 3, 4 ]
  , [ 2,-1, 4,-3 ]
  , [ 3,-4,-1, 2 ]
  , [ 4, 3,-2,-1 ] ]

valueof = { 'i' : 2, 'j' : 3, 'k' : 4 }

def sign(x):
  if x > 0:
    return 1
  elif x < 0:
    return -1
  else:
    assert False

def mul(x, y):
  return sign(x) * sign(y) * mul_table[abs(x) - 1][abs(y) - 1]

def mul_rev(x, y):
  return mul(y, x)

def is_i(x):
  return x == 2
def is_k(x):
  return x == 4

def prefix(mul_gen, test, S):
  acc = one()
  for i in range(len(S)):
    acc = mul_gen(acc, valueof[S[i]])
    if test(acc):
      return i + 1
  return -1

def power(x, n):
  y = one()
  for i in range(45,-1,-1):
    y = mul(y, y)
    if (n >> i) & 1 != 0:
      y = mul(y, x)
  #print('power',x,n,y)
  return y

def solve(X, S):
  acc = one()
  for x in S:
    acc = mul(acc, valueof[x])
  if not is_minus_one(power(acc, X)):
    return False
  S5 = S + S + S + S + S
  n1 = prefix(mul, is_i, S5)
  n2 = prefix(mul_rev, is_k, S5[::-1])
  #print(S5[:n1],S5[-n2:])
  if n1 < 0 or n2 < 0 or n1 + n2 > len(S) * X:
    return False
  return True

lines = sys.stdin.readlines()
for i in range(int(lines[0].strip())):
  ws = [int(x) for x in lines[1+2*i].split()]
  s = lines[2+2*i].strip()
  r = solve(ws[1], s)
  sys.stdout.write('Case #{}: {}\n'.format(i+1, 'YES' if r else 'NO'))
