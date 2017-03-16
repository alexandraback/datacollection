import os
import sys

kases = int(input())

ts = []
for i in range(0,2000001):
  num = i
  li = len(str(num)) - 1
  s = []
  for j in range(li+1):
    c = num % 10
    num = num / 10
    num += (10 ** li) * c
    if num not in s:
      s.append(num)
  ts.append(s)

for kase in range(kases):
  print >> sys.stderr, 'kase %s' % kase
  l = raw_input().split()
  a = int(l[0])
  b = int(l[1])

  t = 0
  for i in range(a, b+1):
    for v in ts[i]:
      if v > i and v <= b:
        t += 1

  print 'Case #%s: %s' % (kase+1, t)