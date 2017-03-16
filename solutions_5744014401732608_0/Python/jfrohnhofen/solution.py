#!/usr/bin/python

from sys import stdin as I

def binary(num, length=8, pre='', spacer=0):
    return '{0}{{:{1}>{2}}}'.format(pre, spacer, length).format(bin(num)[2:])

def solve(n):
  B, M = map(int, I.readline()[:-1].split(' '))

  if 2 ** (B - 2) < M:
    print("Case #%i: IMPOSSIBLE" % (n+1))
    return

  direct = 0
  if 2 ** (B - 2) == M:
    M -= 1
    direct = 1

  print("Case #%i: POSSIBLE" % (n+1))
  print(binary(M * 2 + direct, B))
  for i in range(B-2):
    print('0' * (i+2) + '1' * (B-i-2))
  print('0' * B)

T = int(I.readline())
for i in range(T):
    solve(i)
