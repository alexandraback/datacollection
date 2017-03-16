vowels = "aeiou"
for tc in xrange(1,1+input()):
  name, n = raw_input().split()
  n = int(n)
  ans = 0
  for size in xrange(n, len(name)+1):
    for start in xrange(0, len(name) - size + 1):
      cons = 0
      m = 0
      for c in name[start: start+size]:
        if c in vowels:
          cons = 0
        else:
          cons += 1
        m = max(m, cons)
      if m >= n:
        ans += 1
  print "Case #%d: %d" % (tc, ans)
