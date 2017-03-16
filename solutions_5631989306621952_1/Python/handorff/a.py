def solve(s):
  out = ''
  for c in s:
    first = c + out
    last = out + c
    out = max(first, last)
  return out

cases = []
t = int(raw_input())
for i in xrange(t):
  cases.append(raw_input())

for i, case in enumerate(cases):
  print "Case #%d: %s" % (i + 1, solve(case)) 
