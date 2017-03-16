#! /usr/bin/env python
# -*- coding: utf-8 -*

import fractions

T = int(raw_input())

for tests in xrange(1, T + 1):
  frac = raw_input()
  frac = fractions.Fraction(frac)
  
  sec_pow = [2**i for i in xrange(40)]
  
  if frac.denominator not in sec_pow:
    print "Case #%d: %s" % (tests, "impossible")
    continue  
  
  cnt = 0
  while cnt < 40:
    CD = 2 * frac - 1
    if CD < 0:
      frac *= 2
      cnt += 1
    else:
      break
    
  
  print "Case #%d: %s" % (tests, str(cnt + 1) if cnt < 40 else "impossible")
