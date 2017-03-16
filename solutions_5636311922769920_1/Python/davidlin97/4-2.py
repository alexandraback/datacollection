# 4:24 4:44
# need to check K values
# one time check C values

def solve(K, C):

  not_used = range(K)
  ans = []

  for count in range(0,K,C):
    # print not_used
    tmp=0
    for i in range(C):
      tmp += not_used[-1]
      tmp *= K
      if len(not_used)>1: not_used.pop()
    tmp /= K
    ans.append(tmp+1)
  return ans

T = int(raw_input())

for i in xrange(1, T+1):
  K, C, S = [int(s) for s in raw_input().split(" ")]
  if C*S < K:
    print "Case #{}: IMPOSSIBLE".format(i)
    continue
  print "Case #{}:".format(i),
  for ele in solve(K,C):
    print ele,
  print