import itertools
T = int(raw_input())
for t in xrange(1, T + 1):
  K, L, S = (int(token) for token in raw_input().split())
  A = raw_input()
  B = raw_input()
  worst = 0
  average = 0
  for x in itertools.product(A, repeat = S):
    substrings = sum(1 for i in xrange(S - L + 1) if B == ''.join(x[i: i + L]))
    worst = max(substrings, worst)
    average += substrings
  print "Case #%d: %.9f" % (t, worst - float(average) / K**S)
