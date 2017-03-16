t = int(raw_input())
for i in xrange(1, t + 1):
  k, c, s = [int(s) for s in raw_input().split(" ")]  
  output = " ".join(str(n) for n in range(1, s+1))
  print "Case #{}: {}".format(i, output)