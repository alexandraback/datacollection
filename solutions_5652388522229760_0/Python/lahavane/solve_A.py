#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

def get_new_digits(n, digits):
  for d in n:
    if d not in digits:
      digits.append(d)
  return digits

def solve(t, i):
  if t == '0':
    print 'case #%d: INSOMNIA'%i
    return
  n = t
  offset = int(t)
  digits = get_new_digits(n, [])
  while len(digits) < 10:
    n = str(int(n)+offset)
    #print n
    digits = get_new_digits(n, digits)
  print 'case #%d: %s'%(i, n)

if __name__ == "__main__":
  with open(sys.argv[1]) as f:
    buf = f.read()
  t = buf.split("\n")
  nb_tests = int(t[0])
  t = t[1:]
  for k in xrange(0, nb_tests):
    solve(t[k], k+1)
