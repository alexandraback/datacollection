def is_threashold(g, s):
  below = [x for x in s if x < g]
  if not below:
    return False
  return (sum(below) + 1.0) / len(below) < g

T = int(raw_input())
for t in xrange(T):
  a = [int(x) for x in raw_input().split()]
  a = a[1:]

  s = sum(a)
  a = [float(x) / s for x in a]

  th = 1.0
  for g in sorted(a):
    if is_threashold(g, a):
      th = g
      break

  below = [x for x in a if x < th]
  goal = (sum(below) + 1.0) / len(below)

  print "Case #%i: %s" % (t+1, " ".join([str(0.0 if x >= th else 100.0 * (goal - x)) for x in a]))
