import itertools

def solve():
  N = input()
  words = []

  for i in xrange(N):
    w1, w2 = raw_input().strip().split()
    words += [(w1, w2)]

  best = 0
  for t in itertools.product([0, 1], repeat = N):
    ok = True
    w1s = set()
    w2s = set()

    for i in xrange(N):
      w1, w2 = words[i]
      if t[i]:
        w1s.add(w1)
        w2s.add(w2)
    for i in xrange(N):
      w1, w2 = words[i]
      if not t[i]:
        if w1 not in w1s:
          ok = False
          break
        if w2 not in w2s:
          ok = False
          break
    if ok:
      #print t
      best = max(best, N - sum(t))

  return best

T = input()
for i in range(T):
  print 'Case #%d: %d' % (i+1, solve())
