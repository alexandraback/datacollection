from sys import stdin

def solve(K,C,S):
  return ' '.join(str(x) for x in range(1,S+1))

for case in xrange(1,1+int(stdin.readline())):
  (K,C,S) = tuple(int(x) for x in stdin.readline().split())
  print "Case #%d: %s" % (case, solve(K,C,S))