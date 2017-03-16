t=input()
for i in xrange(t):
  n,j=map(int,raw_input().strip().split())
  print "Case #"+str(i+1)+":"
  for c in xrange(j):
    #generate the cth coin using polynomials which are always divisible by b+1
    coin="11"
    cc=c
    while cc>0:
      if cc%2==0:
        coin="00"+coin
      else:
        coin="11"+coin
        cc-=1
      cc/=2
    while len(coin)<n-2:
      coin="00"+coin
    coin="11"+coin
    #verify coin
    for base in xrange(2,11):
      cval=int(coin,base)
      if cval%(base+1)!=0:
        print "error",coin,base
    #print coin
    print coin,3,4,5,6,7,8,9,10,11

  
