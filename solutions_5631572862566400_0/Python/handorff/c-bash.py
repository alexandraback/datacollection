import itertools

# is student a neighbor of his bff
def test_helper(s, n1, n2, bffs):
  return n1 == bffs[s - 1] or n2 == bffs[s - 1]

def test(p, bffs):
  # first
  s = p[0]
  n1 = p[1]
  n2 = p[-1]
  if not test_helper(s, n1, n2, bffs):
    return False

  # last
  s = p[-1]
  n1 = p[-2]
  n2 = p[0]
  if not test_helper(s, n1, n2, bffs):
    return False

  # others
  for i in xrange(1, len(p) - 1):
    if not test_helper(p[i], p[i-1], p[i+1], bffs):
      return False

  return True

def solve(case):
  n, bffs = case
  for i in range(n)[::-1]:
    for p in itertools.permutations(range(1, n + 1), i + 1):
      if test(p, bffs):
        return i + 1
  return 0

cases = []
t = int(raw_input())
for i in xrange(t):
  n = int(raw_input())
  bffs = map(int, raw_input().split(' '))
  cases.append((n, bffs))

for i, case in enumerate(cases):
  print "Case #%d: %s" % (i + 1, solve(case)) 
