T = int(raw_input())

for case in xrange(1, T+1):
  [K, C, S] = map(int, raw_input().split())
  if C == 1:
    if S < K:
      print("Case #%d: IMPOSSIBLE" % (case))
    else:
      print("Case #%d: %s" % (case, " ".join(map(str,range(1,K+1)))))
    continue
  if 2*S < K:
      print("Case #%d: IMPOSSIBLE" % (case))
      continue
  res = []
  x = 0
  pot = K ** C
  while x < K/2:
    res.append(2*x*(K+1) + 2)
    x+=1
  if K%2:
    res.append(K)

  print("Case #%d: %s" % (case, " ".join(map(str, res))))
