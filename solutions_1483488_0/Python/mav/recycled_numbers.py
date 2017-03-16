cases = int(raw_input().strip())
for x in range(1, cases+1):
  s = set()
  data = raw_input().strip().split()
  l = int(data[0])
  u = int(data[1])
  num = 0

  for n in range(l, u+1):
    p = str(n)
    for i in range(1, len(p)):
      w = p[i:] + p[:i]
      e = int(w)
      if e <= u and e >= l and e != n and (e, n) not in s and (n, e) not in s:
        num += 1
        s.add((e, n))
        s.add((n, e))

  print "Case #" + str(x) + ": " + str(num)
