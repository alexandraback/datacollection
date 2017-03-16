#!/usr/bin/env python

priming = [
  ('ejp mysljylc kd kxveddknmc re jsicpdrysi',
   'our language is impossible to understand'),
  ('rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd',
   'there are twenty six factorial possibilities'),
  ('de kr kd eoya kw aej tysr re ujdr lkgc jv',
   'so it is okay if you want to just give up')
]

mapping = {' ': ' '}

for i in xrange(ord('a'), ord('z')+1):
  mapping[chr(i)] = chr(i).upper()

for data in priming:
  for i in xrange(len(data[0])):
    mapping[data[0][i]] = data[1][i]

mapping['z'] = 'q'
mapping['q'] = 'z'
# debug
#for i in sorted(mapping.keys()):
#  print '%s: %s' % (i, mapping[i])
# end debug

def translate(s):
  global mapping
  return ''.join([mapping[i] for i in s])

cases = int(raw_input())
for i in xrange(1, cases+1):
  print 'Case #%d:' % i,
  print translate(raw_input())
