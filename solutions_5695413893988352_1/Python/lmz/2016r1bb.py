import sys
import itertools
sys.setrecursionlimit(10000)

tc = int(sys.stdin.readline().strip())

def max_v(S):
  res = 0
  for s in S:
    if s == '?': res = 10 * res + 9
    else: res = 10 * res + int(s)
  return res

def min_v(S):
  res = 0
  for s in S:
    if s == '?': res = 10 * res
    else: res = 10 * res + int(s)
  return res

for tmp_tc in xrange(tc):
  [ C, J ] = sys.stdin.readline().strip().split(' ')

  L = len(C)
  cache = {}

  def dp(i):
    if i == L: return 0, 0
    if i in cache: return cache[i]

    basis = 10**(L-i-1)
    candidates = []
    if C[i] == '?' and J[i] == '?':
      candidates.append(dp(i+1))
      candidates.append((max_v(C[i+1:]), basis + min_v(J[i+1:])))
      candidates.append((basis + min_v(C[i+1:]), max_v(J[i+1:])))
    elif C[i] == '?':
      digit = int(J[i])
      c1, j1 = dp(i+1)
      candidates.append((digit*basis + c1, digit*basis + j1))
      if digit > 0:
        candidates.append(((digit-1)*basis + max_v(C[i+1:]), digit*basis + min_v(J[i+1:])))
      if digit < 9:
        candidates.append(((digit+1)*basis + min_v(C[i+1:]), digit*basis + max_v(J[i+1:])))
    elif J[i] == '?':
      digit = int(C[i])
      c1, j1 = dp(i+1)
      candidates.append((digit*basis + c1, digit*basis + j1))
      if digit > 0:
        candidates.append((digit*basis + min_v(C[i+1:]), (digit-1)*basis + max_v(J[i+1:])))
      if digit < 9:
        candidates.append((digit*basis + max_v(C[i+1:]), (digit+1)*basis + min_v(J[i+1:])))
    elif C[i] == J[i]:
      digit = int(C[i])
      c1, j1 = dp(i+1)
      candidates.append((digit*basis + c1, digit*basis + j1))
    elif C[i] < J[i]:
      digit_c = int(C[i])
      digit_j = int(J[i])
      candidates.append((digit_c*basis + max_v(C[i+1:]), digit_j*basis + min_v(J[i+1:])))
    else:
      digit_c = int(C[i])
      digit_j = int(J[i])
      candidates.append((digit_c*basis + min_v(C[i+1:]), digit_j*basis + max_v(J[i+1:])))

    current_min, res = None, None
    for (c, j) in sorted(candidates):
      d = abs(c - j)
      if current_min is None or d < current_min:
        current_min = d
        res = c, j
    cache[i] = res
    return res

  res_c, res_j = dp(0)
  res_c = str(res_c).zfill(L)
  res_j = str(res_j).zfill(L)
  print "Case #%d: %s %s" % (1+tmp_tc, res_c, res_j)
