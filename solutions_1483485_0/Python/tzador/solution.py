#!/usr/bin/env python
import re

test = 'small'
input = open('%s.in'%test)
output = open('%s.out'%test, 'w')

not_letters = re.compile(r'[^a-z]')

sample_in = not_letters.sub('', """
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
""")

sample_out = not_letters.sub('', """
our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up
""")


mapping = {}
for i in range(len(sample_in)):
  mapping[sample_in[i]] = sample_out[i]
mapping['q'] = 'z'
mapping['z'] = 'q'

T = int(input.readline())
for t in range(T):
  encoded = input.readline().strip()
  decoded = list(range(len(encoded)))
  for i in range(len(encoded)):
    if mapping.get(encoded[i]):
      decoded[i] = mapping[encoded[i]]
    else:
      decoded[i] = encoded[i]
  print >>output, "Case #%d:"%(t+1), ''.join(decoded)
