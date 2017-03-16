"""Revenge of the Pancakes

Two observations:
  1. The '+' at the end don't matter.
  2. Each flip changes the number of sign changes by at most 1.
"""

try: input = raw_input
except NameError: pass

T = int(input())

for i in range(1, T+1):
  last = ''
  ans = 0
  for c in input():
    if c != last:
      ans += 1
    last = c
  if last == '+':
    ans -= 1
  print('Case #%d: %d' % (i, ans))
