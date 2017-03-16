for cas in xrange(1, input()+1):
  print "Case #%d:" % cas,
  S = raw_input().split(" ")[1]
  res = 0
  a = 0
  for k in xrange(len(S)):
    if a < k:
      res += k-a
      a = k
    a += int(S[k])
  print res
