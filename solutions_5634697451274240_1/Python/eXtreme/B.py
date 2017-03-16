import sys

lines = sys.stdin.readlines()[1:]

lines = [l.strip()[::-1] for l in lines]

for tnr, l in enumerate(lines):
  l = '+' + l
  c = 0
  for i in range(0, len(l)-1):
    if l[i] != l[i+1]:
      c += 1

  print 'Case #%d: %d' % (tnr + 1, c)

