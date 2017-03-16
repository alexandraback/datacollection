t=input()
for i in xrange(t):
  j,p,s,k=map(int,raw_input().strip().split())
  if k>=s:
    print "Case #"+str(i+1)+": "+str(j*p*s)
    for jj in xrange(1,j+1):
      for pp in xrange(1,p+1):
        for ss in xrange(1,s+1):
          print jj,pp,ss
  elif k>=p:
    print "Case #"+str(i+1)+": "+str(j*p*k)
    for jj in xrange(1,j+1):
      for pp in xrange(1,p+1):
        for ss in xrange(1,k+1):
          print jj,pp,ss
  elif (j,p,s,k)==(1,3,3,2):
    print "Case #"+str(i+1)+": 6"
    print 1,1,1
    print 1,1,2
    print 1,2,3
    print 1,2,1
    print 1,3,2
    print 1,3,3
  elif (j,p,s,k)==(2,3,3,2):
    print "Case #"+str(i+1)+": 12"
    print 1,1,1
    print 1,1,2
    print 1,2,3
    print 1,2,1
    print 1,3,2
    print 1,3,3
    print 2,1,1
    print 2,1,2
    print 2,2,3
    print 2,2,1
    print 2,3,2
    print 2,3,3
  elif (j,p,s,k)==(3,3,3,2):
    print "Case #"+str(i+1)+": 18"
    print 1,1,1
    print 1,1,2
    print 1,2,3
    print 1,2,1
    print 1,3,2
    print 1,3,3
    print 2,1,3
    print 2,1,1
    print 2,2,2
    print 2,2,3
    print 2,3,1
    print 2,3,2
    print 3,1,2
    print 3,1,3
    print 3,2,1
    print 3,2,2
    print 3,3,3
    print 3,3,1
  elif (j,p,s,k) in ((1,2,2,1),(1,2,3,1)):
    print "Case #"+str(i+1)+": 2"
    print 1,1,1
    print 1,2,2
  elif (j,p,s,k)==(1,3,3,1):
    print "Case #"+str(i+1)+": 3"
    print 1,1,1
    print 1,2,2
    print 1,3,3
  elif (j,p,s,k) in ((2,2,2,1),(2,2,3,1)):
    print "Case #"+str(i+1)+": 4"
    print 1,1,1
    print 1,2,2
    print 2,1,2
    print 2,2,1
  elif (j,p,s,k)==(2,3,3,1):
    print "Case #"+str(i+1)+": 6"
    print 1,1,1
    print 1,2,2
    print 1,3,3
    print 2,1,2
    print 2,2,3
    print 2,3,1
  elif (j,p,s,k)==(3,3,3,1):
    print "Case #"+str(i+1)+": 9"
    print 1,1,1
    print 1,2,2
    print 1,3,3
    print 2,1,2
    print 2,2,3
    print 2,3,1
    print 3,1,3
    print 3,2,1
    print 3,3,2

    
