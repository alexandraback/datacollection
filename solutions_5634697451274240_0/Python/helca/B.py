t = int(raw_input())
for i in xrange(1, t + 1):
  S = raw_input() + '+'
  a, j = 0, 1
  while j < len(S):
  	if S[-j] != S[-j-1]:
  		a += 1
  	j += 1
  print "Case #{}: {}".format(i, a)