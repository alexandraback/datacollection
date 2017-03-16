#!/usr/bin/env python

# Highest non-surprising individual score, given a total
max_n = [-1]*31

# Highest surprising individual score, given a total
max_s = [-1]*31

# Generate
for x in xrange(0, 11):
  # Non-surprising
  total = 3*x
  max_n[total] = max(x, max_n[total])
  if x < 10:
    total = 3*x+1
    max_n[total] = max(x+1, max_n[total])
    total = 3*x+2
    max_n[total] = max(x+1, max_n[total])

  # Surprising
  if x < 9:
    total = 3*x+2
    max_s[total] = max(x+2, max_n[total])
    total = 3*x+3
    max_s[total] = max(x+2, max_n[total])
    total = 3*x+4
    max_s[total] = max(x+2, max_n[total])

#debug
#print ' '.join(['%2d' % i for i in max_n])
#print ' '.join(['%2d' % i for i in max_s])
#enddebug

def algo(N, S, p, totals):
  # except where surprising is impossible, surprising always
  # yields a maximum individual score >= the non-surprising one
  # when surprising quota is scarce:
  # process from smallest to largest
  # choosing surprising if only when it will push something from < p to == p
  # when surprising quota is excess:
  # actually, i think having excess surprisng quota remaining doesn't matter
  # since anything that was non-surprising can be equivalent if surprising
  # unless total is 0, 1, 29 or 30
  global max_n, max_s

  # convert totals to a frequency thing
  totals_freq = [0]*31
  for i in totals:
    totals_freq[i] += 1

  counter = 0

  # now check each thing discretely, handling
  # guaranteed non-surprising cases first
  for i in [0, 1, 29, 30]:
    if max_n[i] >= p:
      counter += totals_freq[i]

  # now for the rest potential surprisings
  for i in xrange(2, 29):
    if max_n[i] >= p:
      counter += totals_freq[i]
    elif max_s[i] >= p:
      to_add = min(totals_freq[i], S)
      counter += to_add
      S -= to_add
  
  return counter

cases = int(raw_input())
for i in xrange(1, cases+1):
  print 'Case #%d:' % i,
  line = raw_input()
  N, S, p, totals_str = line.split(' ', 3)
  N = int(N)
  S = int(S)
  p = int(p)
  totals = [int(j) for j in totals_str.split(' ')]
  print algo(N, S, p, totals)
