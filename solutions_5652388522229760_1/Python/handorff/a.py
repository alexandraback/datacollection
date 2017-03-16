def solve(n):
  if n == 0:
    return "INSOMNIA"

  total = n
  seen = set()
  while True:
    new_digits = set(str(total))
    seen = seen.union(new_digits)
    if len(seen) == 10:
      return str(total)
    total += n

cases = []
t = int(raw_input())
for i in xrange(t):
  cases.append(int(raw_input()))

for i, case in enumerate(cases):
  print "Case #%d: %s" % (i + 1, solve(case))
