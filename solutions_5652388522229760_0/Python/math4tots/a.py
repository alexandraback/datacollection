# Counting Sheep

def solve(N):
  if N == 0:
    return 'INSOMNIA'
  x = N
  seen = set(str(x))
  while len(seen) < 10:
    x += N
    seen |= set(str(x))
  return x

T = int(input())

for i in range(1, T+1):
  print('Case #%d: %s' % (i, solve(int(input()))))
