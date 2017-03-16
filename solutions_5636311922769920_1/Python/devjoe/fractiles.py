t=input()
for i in xrange(t):
  k,c,s=map(int,raw_input().strip().split())
  if c*s<k:
    print "Case #"+str(i+1)+": IMPOSSIBLE"
    continue
  res="Case #"+str(i+1)+": "
  selections=int((k+c-1)/c)
  digits=range(k)+[0]*(selections*c-k)
  for sel in xrange(selections):
    digitsthistime=digits[(c*sel):(c*sel+c)]
    sol=0
    for digit in digitsthistime:
      sol=sol*k+digit
    res+=str(sol+1)+" "
  print res
  
  
