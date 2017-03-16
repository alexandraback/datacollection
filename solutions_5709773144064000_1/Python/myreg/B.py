T = int(raw_input())
for i in range(T):
  C, F, X = (float(x) for x in raw_input().split())
  t = 0
  s = X/2;
  k = 1
  while 1:
    t = t + C / (2 + (k-1)*F)
    ss = t + X / (2 + k*F)
    if ss > s: break
    k += 1
    s = ss
  print "Case #%i: %.7f"%(i+1, s)