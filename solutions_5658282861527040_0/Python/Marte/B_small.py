for cas in xrange(1, input()+1):
  print "Case #%d:" % cas,
  A, B, K = map(int, raw_input().split(' '))
  x = 0
  for a in xrange(A):
    for b in xrange(B):
      if a & b < K:
        x += 1
  print x
