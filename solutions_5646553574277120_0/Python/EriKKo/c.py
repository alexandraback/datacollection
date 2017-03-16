T = int(raw_input())
for test in range(T):
  C,D,V = map(int,raw_input().split())
  a = sorted(map(int,raw_input().split()))
  n = 1
  res = 0
  i = 0
  while n < V:
	if i < len(a) and a[i] <= n:
	  n += C*a[i]
	  i += 1
	else:
	  res += 1
	  n += C*n
  print "Case #%d: %d" % (test+1,res)
