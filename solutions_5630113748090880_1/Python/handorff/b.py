import collections

def solve(case):
  n, rows = case
  counts = collections.defaultdict(int)
  out = []

  for row in rows:
    for height in row:
      counts[height] = (counts[height] + 1) % 2

  return ' '.join(map(str, sorted([k for k, v in counts.iteritems() if v == 1])))

cases = []
t = int(raw_input())
for i in xrange(t):
  n = int(raw_input())
  rows = []
  for j in xrange(2 * n - 1):
    rows.append(map(int, raw_input().split(' ')))
  cases.append((n, rows))

for i, case in enumerate(cases):
  print "Case #%d: %s" % (i + 1, solve(case)) 
