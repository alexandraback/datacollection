T = input()

for _ in range(1, T+1):
  k, c, s = map(int, raw_input().split())
  print 'Case #{}: {}'.format(_, ' '.join(map(str, range(1, s+1))))
