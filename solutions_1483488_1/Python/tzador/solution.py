
def recycle(n):
  ns = str(n)
  for i in range(1, len(ns)):
    ms = ns[i:]+ns[:i]
    m = int(ms)
    ms = str(m)
    if len(ms) == len(ns):
      yield m

def solve(A, B):
  cnt = 0
  for n in range(A, B):
    for m in set(recycle(n)):
      if n < m and m <= B:
        cnt += 1
  return cnt

test = 'large'
input = open('%s.in'%test)
output = open('%s.out'%test, 'w')

T = int(input.readline())
for t in range(T):
  print t, T
  ints = map(int, input.readline().split())
  print >>output, "Case #%d:"%(t+1), solve(ints[0], ints[1])

