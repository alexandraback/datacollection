def solve(case):
  [k, c, s] = case
  return ' '.join(map(str, [(i - 1) * (k ** (c - 1)) + 1 for i in xrange(1, k + 1)]))

cases = []
t = int(raw_input())
for i in xrange(t):
  cases.append(map(int, raw_input().split(' ')))

for i, case in enumerate(cases):
  print "Case #%d: %s" % (i + 1, solve(case))
