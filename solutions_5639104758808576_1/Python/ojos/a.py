#!/usr/bin/env python

for nnn in xrange(1, int(raw_input())+1):
  print "Case #%d:" % (nnn),
  max_shyness, counts = [x for x in raw_input().split()]
  total = sum([int(x) for x in counts])
  stood, num_friends = 0, 0
  for i in xrange(0, int(max_shyness)+1):
    if stood == total + num_friends:
      break
    if stood < i:
      num_friends += i-stood
      stood = i
    stood += int(counts[i])
  print num_friends

