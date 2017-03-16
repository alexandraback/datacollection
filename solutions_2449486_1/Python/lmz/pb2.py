import sys

def is_ok(lines, n, m):
  for i, line in enumerate(lines):
    for j, elm in enumerate(line):
      max_h = max([lines[i][k] for k in xrange(m)])
      max_v = max([lines[k][j] for k in xrange(n)])
      if elm < max_h and elm < max_v: return False
  return True

samples = int(sys.stdin.readline().rstrip())
for i in xrange(samples):
  [n, m] = sys.stdin.readline().rstrip().split()
  n, m = int(n), int(m)
  lines = []
  for y in xrange(n):
    line_s = sys.stdin.readline().rstrip().split()
    lines.append(map(lambda x: int(x), line_s))
  print "Case #%d: %s" % (i+1, "YES" if is_ok(lines, n, m) else "NO")
