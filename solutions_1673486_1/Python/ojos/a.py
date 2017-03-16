NNN = int(raw_input())
for nnn in xrange(1, NNN+1):
  print "Case #%d:" % (nnn),
  A, B = (int(x) for x in raw_input().split())
  P = [float(x) for x in raw_input().split()]
  L = [B+2, A+B+1]
  prod = 1.0
  count = 2*A - 2
  for i in xrange(A):
    prod *= P[i]
    L.append(prod*(B-A+1+count) + (1-prod)*(B-A+2+B+count))
    count -= 2
  result = min(L)
  print "%0.6f" % (result)
