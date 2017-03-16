
T = int(raw_input())

for t in range(T):
  d = {}
  N = int(raw_input())
  
  for i in range(2*N-1):
    a = [int(j) for j in raw_input().split()]
    for e in a:
      if e in d:
        d[e] += 1
      else:
        d[e] = 1

  b = []
  for k in d:
    if (d[k] % 2 == 1):
      b.append(k)

  b.sort()
  ans = ""
  for c in b:
    ans += str(c) + " "
    

  print "Case #{}: {}".format(t+1, ans.strip())
