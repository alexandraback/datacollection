T = int(raw_input())

for i in xrange(T):
  C, F, X = raw_input().split()
  C = float(C)
  F = float(F)
  X = float(X)

  # Compute
  rate = 2.0 # initial rate
  timing = 0.0
  if X <= C:
    timing = X / rate
  else:
    while (True):
      timing += C / rate
      tmp1 = (X - C) / rate
      tmp2 = X / (rate + F)
      if tmp1 < tmp2:
        timing += tmp1
        break
      else: # by a farm -> cookies = 0
        rate += F

  print 'case #' + str(i+1) + ': ' + '%.7f' % timing
