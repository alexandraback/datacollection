#!/usr/bin/env python
import string
import sys


letters = string.lowercase
consonants = [l for l in letters if l not in "aeiou"]


def is_good(s, n):
  return len(s) == n and all([c in consonants for c in s])


def n_value(s, n):
  """O(L^2) algo"""
  bs = [is_good(s[k:k + n], n) for k in range(len(s))]
  val = 0
  for left in range(len(s)):
    if True not in bs[left:]: break
    min_len = bs[left:].index(True) + n
    max_len = len(s) - left
    val += max_len - min_len + 1
  return val


# process all tests
T = int(sys.stdin.readline())
for i in range(T):
  s, n = sys.stdin.readline().strip().split()
  print 'Case #%d: %s' % (i + 1, n_value(s, int(n)))
