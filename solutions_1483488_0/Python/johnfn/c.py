lines = [l[:-1] for l in open("cin")][1:]

case = 0
for l in lines:
  case +=1

  a, b = [int(x) for x in l.split(" ")]

  #faster: array
  d = {}
  count = 0
  for x in xrange(a, b+1):
    if x in d: continue

    def c(s, k): return int(s[k:] + s[:k])

    s = str(x)
    cycle = set([c(s, k) for k in range(1, len(s) + 1) if c(s,k) >= a and c(s, k) <= b])
    if len(cycle) > 1:
      for c in cycle: d[c] = True
      count += len(cycle) * (len(cycle) - 1)/2

  print "Case #%d:" % case, count
