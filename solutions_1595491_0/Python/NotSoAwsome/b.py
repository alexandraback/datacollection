import os

kases = int(input())

for kase in range(kases):
  l = raw_input().split()
  n = int(l[0])
  s = int(l[1])
  p = int(l[2])
  t = 0
  for i,v in enumerate(l):
    v = int(v)
    if i >= 3:
      if v % 3 == 0 and v / 3 >= p:
        t += 1
      elif (v + 2) / 3 >= p and (v + 2) / 3 - 1 >= 0:
        t += 1
        #print v, (v+2) / 3, (v + 2) / 3 - 1
      elif s > 0 and (v+4) / 3 >= p and (v+4) / 3 - 2 >= 0:
        t += 1
        s -= 1
        #print ' ', v, (v+4) / 3, (v+4) / 3 - 2

  print 'Case #%s: %s' % (kase+1, t)