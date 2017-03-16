for xx in xrange(int(raw_input())):
  print "Case #%d:"%(xx+1),
  a=[0]*10
  x=int(raw_input())
  if not x:
    print "INSOMNIA"
    continue
  y=x
  while y:
    a[y%10]=1
    y=y/10
  ans=x
  while 0 in a:
    ans+=x
    y=ans
    while y:
      a[y%10]=1
      y=y/10
  print ans
  
