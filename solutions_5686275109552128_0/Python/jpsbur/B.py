#!/usr/bin/python3

def solve ():
  n = int (input ())
  a = [int (x) for x in input ().split ()]
  a.sort ()
  ans = a[-1]
  m = ans
  for i in range (1, m + 1):
    cnt = 0
    for x in a:
      cnt += (x - 1) // i
    ans = min (ans, i + cnt)
  return ans

T = int (input ())
for t in range (T):
  print ('Case #' + str (t + 1) + ': ' + str (solve ()))
