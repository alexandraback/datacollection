
def test():
  K, C, S = map(int, raw_input().split())
  
  coordinates = [[min(x, K-1) for x in xrange(first, first+C)] for first in xrange(0, K, C)]
  questions = map(lambda c: reduce(lambda accum, x: accum*K+x, c), coordinates)
  if S < len(questions):
    print 'IMPOSSIBLE',
  else:
    print ' '.join(map(lambda i: str(i+1), questions)),


TESTS = int(raw_input())
for c in xrange(1, TESTS+1):
  print 'Case #{}:'.format(c),
  test()
  print
  
