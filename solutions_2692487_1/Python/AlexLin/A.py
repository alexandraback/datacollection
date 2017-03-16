import sys

lines = [L.strip() for L in sys.stdin.read().splitlines()]
lines = iter(lines)
T = int(next(lines))

def min_step(A, motes):
  if (len(motes) > 0 and A == 1):
    return 1000
  step = 0
  while motes:
    while (A <= motes[0]):
      step += 1
      A += A - 1
    while motes and (A > motes[0]):
      A += motes[0]
      motes.pop(0)
  return step

for i in range(T):
  A, N = list(map(int, next(lines).split()))
  motes = list(map(int, next(lines).split()))
  motes.sort()
  ans = N
  for r in range(N + 1):
    ans = min(ans, min_step(A, motes[:N - r]) + r)
  print("Case #%d: %d" % (i + 1, ans))

