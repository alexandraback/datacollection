#!/usr/bin/python3

def solve(s):
  x = ''
  for c in s:
    x = max(c + x, x + c)
  return x

nt = int(input())
for tt in range(nt):
  s = input()
  print('Case #' + str(tt + 1) + ': ' + solve(s))
