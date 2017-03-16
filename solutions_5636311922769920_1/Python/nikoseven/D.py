def chunks(l, n):
  for i in range(0, len(l), n):
    yield l[i:i+n]

T = int(raw_input())
for _case in range(T):
  K, C, S = [int(x) for x in raw_input().split()]
  ans = ''
  if C * S < K:
    ans = "IMPOSSIBLE"
  else:
    r = []
    for z in chunks(range(0,K), C):
      r.append(sum([z[i]*(K**i) for i in range(0, len(z))])+1)
    ans = " ".join([str(x) for x in r])
  print "Case #%d: %s" % (_case+1, ans)