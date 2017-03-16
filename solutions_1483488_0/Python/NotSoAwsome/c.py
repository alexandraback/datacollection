import os

kases = int(input())

for kase in range(kases):
  l = raw_input().split()
  a = int(l[0])
  b = int(l[1])

  t = 0
  for i in range(a,b):
    num = i
    li = len(str(num)) - 1
    s = {}
    for j in range(li+1):
      c = num % 10
      num = num / 10
      num += (10 ** li) * c
      if num > i and num <= b:
        s[num] = 1
    t += len(s)

  print 'Case #%s: %s' % (kase+1, t)