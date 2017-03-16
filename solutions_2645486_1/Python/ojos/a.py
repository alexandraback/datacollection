NNN = int(raw_input())
for nnn in xrange(1, NNN+1):
  print "Case #%d:" % (nnn),
  E, R, N = [int(x) for x in raw_input().split()]
  v = [int(x) for x in raw_input().split()]
  gain = 0
  if E == R:
    gain = sum([E*x for x in v])
  else:
    bigger = [0] * N
    for i in xrange(N-2, -1, -1):
      j = i+1
      while j < N and v[i] >= v[j]:
        bigger[i] += bigger[j] + 1
        j += bigger[j] + 1
    ee = E
    for i in xrange(N-1):
      if bigger[i]==N-i-1:
        gain += ee * v[i]
        ee = R
      else:
        x = E - bigger[i] * R
        x = ee - x
        if x <= 0:
          ee = ee + R
          if ee > E:
            gain += v[i] * (ee-E)
            ee = E
        elif x >= ee:
          gain += ee * v[i]
          ee = R
        else:
          ee = ee - x + R
          gain += x * v[i]
          if ee > E:
            gain += v[i] * (ee-E)
            ee = E
    gain += ee * v[N-1]

  print gain
