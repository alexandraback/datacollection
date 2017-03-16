#!/usr/bin/env python
import sys

def read_test_case(f):
  """read lawn heights"""
  N, M = map(int, f.readline().strip().split())
  return N, M, [map(int, f.readline().strip().split()) for i in range(N)]

def possible(N, M, heights):
  for n in range(N):
    for m in range(M):
      # heights have to be in
      h = heights[n][m]
      if not 1 <= h <= 100:
        return False

      # order of mowing does not matter, furthermore we always mow at most once per row and column (and WLOG precisely once)
      row = heights[n]
      column = [heights[i][m] for i in range(N)]
      if h != min(max(row), max(column)):
        return False
  return True

# process all tests
test_count = int(sys.stdin.readline())
for i in range(test_count):
  test_case = read_test_case(sys.stdin)
  print 'Case #%d: %s' % (i+1, 'YES' if possible(*test_case) else 'NO')
