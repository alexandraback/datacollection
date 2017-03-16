t = raw_input()

for n in xrange(int(t)):
  K, C, S = tuple(map(int, raw_input().split()))
  print 'Case #{}: {}'.format(n + 1, ' '.join(map(str, [i + 1 for i in xrange(K)])))
