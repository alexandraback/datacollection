from sys import stdin

def solve(K,C,S):
  if C >K:
    C=K
  minRes = K-C+1 if K>=C else 1
  if (S<minRes):
    return 'IMPOSSIBLE'
  res=[]
  for i in range(1,minRes+1):
    res.append(i*K**(C-1))
#   res=range(1,S+1)
  return ' '.join(str(x) for x in res)

for case in xrange(1,1+int(stdin.readline())):
  (K,C,S) = tuple(int(x) for x in stdin.readline().split())
  print "Case #%d: %s" % (case, solve(K,C,S))