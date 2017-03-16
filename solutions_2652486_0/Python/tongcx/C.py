from sys import stdin

def work():
  for a in xrange(2, M+1):
    for b in xrange(2, M+1):
      for c in xrange(2, M+1):
        s = set([1,a,b,c,a*b,a*c,b*c,a*b*c])
        if all(i in s for i in v):
          print '%d%d%d' % (a,b,c)
          return
  print '222'

stdin.readline()
R, N, M, K = map(int, stdin.readline().split())
print "Case #1:"
for i in xrange(R):
  v = map(int, stdin.readline().split())
  work()
