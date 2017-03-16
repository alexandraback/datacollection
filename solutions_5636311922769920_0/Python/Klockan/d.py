for xx in range(int(raw_input())):
  print "Case #%d:"%(xx+1),
  k,c,s=map(int,raw_input().split())
  if s*c<k:
    print "IMPOSSIBLE"
    continue
  ans=[]
  cur=0
  while cur < k:
    val=0
    for x in range(c):
      val=val*k+cur
      cur+=1
      if cur==k:
        break
    ans.append(str(val+1))
  print " ".join(ans)
