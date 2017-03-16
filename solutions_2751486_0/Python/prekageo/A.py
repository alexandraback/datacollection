#!/usr/bin/env python

import sys

def rl():
  return sys.stdin.readline().strip()

def solve_one():
  def calc(t):
    count = 0
    for i in xrange(len(t)):
      if t[i] in 'aeiou':
        if count >= n:
          return 1
        count = 0
      else:
        count += 1
    if count >= n:
      return 1
    return 0
  s,n = rl().split()
  n = int(n)
  ret = 0
  for i in xrange(len(s)):
    for j in xrange(i, len(s)):
      ret += calc(s[i:j+1])
  return ret

def main():
  for i in xrange(int(rl())):
    print 'Case #%d: %s' % (i+1,solve_one())

if __name__ == '__main__':
  main()
