# 4:24

def solve(K, C):
  tmp = (K**C - 1)/(K-1) if K!=1 else 1
  return [i*tmp+1 for i in range(K)]

T = int(raw_input())

for i in xrange(1, T+1):
  K, C, S = [int(s) for s in raw_input().split(" ")]
  print "Case #{}:".format(i),
  for ele in solve(K,C):
    print ele,
  print