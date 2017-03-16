from __future__ import division
import math

def nCr(n, r):
  prod = 1
  for i in range(r+1, n+1):
    prod *= i
  for i in range(1, n-r+1):
    prod //= i
  return prod

def tri(n):
  return n * (n + 1) // 2

def op(tc, ans):
  print "Case #" + str(tc) + ":", ans

T = input()
for tc in range(1, T+1):
  N, X, Y = [abs(int(x)) for x in raw_input().split(" ")]
  dist = (X + Y) // 2
  layer = 0
  while tri(2*layer + 1) < N:
    layer += 1
  if layer > dist or (layer == dist and tri(2*layer + 1) == N):
    op(tc, 1)
  elif layer < dist:
    op(tc, 0)
  else:
    xs = N - tri(2*(layer - 1) + 1)
    if xs - (2*layer + 1) >= Y:
      op(tc, 1)
    elif xs < Y or X == 0:
      op(tc, 0)
    else:
      op(tc, sum([nCr(xs, i) for i in range(Y + 1, xs + 1)]) / 2**xs)
