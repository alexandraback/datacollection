T = int(raw_input())
for t in range(T):
  R,C,W = map(int, raw_input().split())
  res = 0
  while C >= 2*W:
	res += R
	C -= W
  res += R-1 + W
  if C != W:
	res += 1
  print "Case #%d: %d" % (t+1,res)
