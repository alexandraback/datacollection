#!/usr/bin/python3

def solve():
  Sm, a = input ().split ()
  Sm = int (Sm)
  res = 0
  cnt = 0
  for i in range (Sm + 1):
    if cnt < i:
      res += i - cnt
      cnt = i
    cnt += int (a[i])
  return res

T = int (input ())
for t in range (T):
  print ('Case #' + str (t + 1) + ': ' + str (solve ()))
