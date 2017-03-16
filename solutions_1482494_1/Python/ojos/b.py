NNN = int(raw_input())
for nnn in xrange(1, NNN+1):
  print "Case #%d:" % (nnn),
  N = int(raw_input())
  a, b, done = [], [], [0]*N
  for i in xrange(N):
    tmp = raw_input().split()
    a.append((i, int(tmp[0]), int(tmp[1])))
    b.append((i, int(tmp[1])))
  a.sort(key=lambda l: l[2])
  b.sort(key=lambda l: l[1])
  count, stars, bad, ia, ib = 0, 0, 0, 0, 0
  while ib < len(b):
    if b[ib][1] <= stars:
      stars += 2 - done[b[ib][0]]
      done[b[ib][0]] = 2
      count += 1
      ib += 1
    else:
      bad = 1
      for i in xrange(len(a)-1, -1, -1):
        if done[a[i][0]] == 0 and a[i][1] <= stars:
          stars += 1
          done[a[i][0]] = 1
          count += 1
          bad = 0
        if not bad: break
      if bad: break

  if bad:
    print "Too Bad"
  else:
    print count
