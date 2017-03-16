def sol(S):
  R = {}
  for i in S:
    if i in R:
      R[i] += 1
    else:
      R[i] = 1
  L = []
  for i, t in R.iteritems():
    if t % 2 == 1:
      L.append(i)
  return " ".join(map(lambda x: str(x), sorted(L)))

# print sol([1,2,3,2,3,5,3,5,6,2,3,4,1,2,3])

t = long(raw_input())  # read a line with a single integer

for i in xrange(1, t + 1):
    N = int(raw_input())
    S = []
    for j in xrange(2 * N - 1):
      S += map(lambda x: int(x), raw_input().split())
    print "Case #{}: {}".format(i, sol(S))
