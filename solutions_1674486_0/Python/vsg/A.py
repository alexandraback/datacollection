def solve(r):
  for i in xrange(len(r)):
    v = set()
    q = [i]
    while q:
      x = q.pop()
      if x in v:
        return "Yes"
      v.add(x)
      q.extend(r[x])
  return "No"

T = int(raw_input())
for t in xrange(T):
  N = int(raw_input())
  
  r = [0] * N
  for i in xrange(N):
    a = raw_input().split()
    r[i] = [int(x)-1 for x in a[1:]]

  print "Case #%i: %s" % (t+1, solve(r))