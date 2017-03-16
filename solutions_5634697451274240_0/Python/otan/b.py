#!/usr/bin/python
import sys

T = int(sys.stdin.readline().strip())
for t in range(T):
  s = list(sys.stdin.readline().strip())
  count = 0
  
  while True:
    # find the first - from the back
    n = 0
    for i, c in enumerate(reversed(s)):
      if c == '-':
        n = len(s) - i
        break

    s = s[:n]
    if not s:
      break
  
    # swap all if first is -, swap + if first is -
    n = len(s)
    if s[0] == '+':
      for i, c in enumerate(s):
        if c != '+':
          n = i
          break

    def swap(c):
      return '-' if c == '+' else '+'

    for i in range((n+1 if n % 2 == 1 else n) / 2):
      temp = s[i]
      s[i] = swap(s[n-1-i])
      s[n-1-i] = swap(temp)
    #print 'flip: ', n, s
    count += 1
  print 'Case #%d: %d' % (t + 1, count)
