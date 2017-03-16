T = int(raw_input())
for i in range(T):
  raw_input()
  n1 = sorted(float(x) for x in raw_input().split())
  k1 = sorted(float(x) for x in raw_input().split())
  n2, k2 = n1[:], k1[:]
  b1 = 0
  while len(n1) > 0:
    if n1[-1] > k1[-1]:
      b1 += 1
      n1.pop()
      k1.pop(0)
    else:
      n1.pop()
      k1.pop()
  b2 = 0
  while len(n2) > 0:
    if n2[0] > k2[0]:
      b2 += 1
      n2.pop(0)
      k2.pop(0)
    else:
      n2.pop(0)
      k2.pop()

  print "Case #%i: %i %i"%(i+1, b2, b1)