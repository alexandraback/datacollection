T = int(raw_input())

for t in range(T):
  df = {}
  ds = {}
  
  N = int(raw_input())
  for i in range(N):
    (A,B) = raw_input().split()
    if A in df:
      df[A]+=1
    else:
      df[A] = 1

    if B in ds:
      ds[B] += 1
    else:
      ds[B] = 1

  ans =  min(N- len(df.keys()), N- len(ds.keys()))


  print "Case #{}: {}".format(t+1, ans)

