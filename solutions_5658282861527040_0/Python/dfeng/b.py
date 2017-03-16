
fname = "B-small-attempt0.in.txt"
# fname = "test.in"

def solve(L):
  A, B, K = L
  # print A, B, K
  cnt = 0
  for i in xrange(A):
    for j in xrange(B):
      if i & j < K:
        cnt += 1
  return cnt

def main():
  with open(fname) as f:
    for i in xrange(int(f.readline())):
      L = map(int, f.readline().split())
      print 'Case #%s: %s' % (i + 1, solve(L))
  
main()