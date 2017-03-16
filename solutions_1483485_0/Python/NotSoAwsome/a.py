import os

trans = [
('ejp mysljylc kd kxveddknmc re jsicpdrysiq',
'our language is impossible to understandz'),
('rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd',
'there are twenty six factorial possibilities'),
('de kr kd eoya kw aej tysr re ujdr lkgc jv',
'so it is okay if you want to just give up')
]

f = [False for i in range(26)]
m = {}
for i in range(3):
  l1 = trans[i][0]
  l2 = trans[i][1]

  for i, c in enumerate(l1):
    m[c] = l2[i]
    if c != ' ':
      f[ord(l2[i]) - ord('a')] = True

for i, v in enumerate(f):
  if not v:
    m['z'] = chr(i + ord('a'))
    break

kases = int(input())
for kase in range(kases):
  l = raw_input()
  o = []

  for c in l:
    o.append(m[c])

  print "Case #%s: %s" % (kase + 1, ''.join(o))