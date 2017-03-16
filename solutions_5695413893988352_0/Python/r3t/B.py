#! /usr/bin/env python
# -*- coding: utf-8 -*

def is_good(num, s):
  snum = str(num).zfill(len(s))
  if len(snum) != len(s):
    return False
  for pos, ch in enumerate(s):
    if s[pos] != '?' and snum[pos] != s[pos]:
      return False
  return True

def solve(a, b):
  sz = len(a)
  x, y = -1, -1
  mm = 10**9
  for i in xrange(10**sz):
    if is_good(i, a):
      for j in xrange(10**sz):
        if is_good(j, b):
          if abs(i - j) < mm:
            x = i
            y = j
            mm = abs(i - j)

  return str(x).zfill(sz), str(y).zfill(sz)

def main():
  t = int(raw_input())

  for test in xrange(1, t + 1):
    a, b = raw_input().split()
    x, y = solve(a, b)
    print 'Case #%d:' % test, x, y

if __name__ == "__main__":
  main()
