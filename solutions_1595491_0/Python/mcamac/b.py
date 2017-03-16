f = open("b.in")
fo = open("bsmall.out", "w")

t = int(f.readline().strip())

for ti in range(t):
  ts = f.readline().strip()
  a = [int(x) for x in ts.split(' ')]
  n = a[0]
  s = a[1]
  p = a[2]
  a = a[3:]

  ok = 0
  sok = 0

  for score in a:
    if score % 3 == 0:
      # a = 3k
      # scores either (k-1, k, k+1) or (k, k, k)
      k = score / 3
      if k >= p:
        ok += 1
      elif k + 1 >= p and k - 1 >= 0:
        sok += 1
    if score % 3 == 1:
      # a = 3k + 1
      # scores either (k, k, k+1), or (k-1, k+1, k+1)
      k = score / 3
      if k + 1 >= p:
        ok += 1
    if score % 3 == 2:
      # a = 3k + 2
      # scores either (k, k, k+2), (k, k+1, k+1)
      k = score / 3
      if k + 1 >= p:
        ok += 1
      elif k + 2 >= p:
        sok += 1



  #print n,s,p,a
  r = ok + min(sok, s)
  fo.write("Case #%d: %d\n" %(ti+1,r))