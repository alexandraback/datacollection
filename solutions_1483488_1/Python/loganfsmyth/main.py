
import sys

count = int(sys.stdin.readline())

for i in range(count):
  (A, B) = sys.stdin.readline().split(' ')
  A = int(A)
  B = int(B)

  vals = set()

  for j in range(A,B+1):
    s = str(j)
    for combo in (int(s[i:] + s[:i]) for i in range(len(s))):
      if combo > j and combo <= B: vals.add((j,combo))

  print 'Case #%d: %s' % (i+1, len(vals))
