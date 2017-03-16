t=input()
for i in xrange(t):
  s=raw_input()+"+"
  flips=0
  for j in xrange(len(s)-1):
    if s[j]!=s[j+1]:
      flips+=1
  print "Case #"+str(i+1)+": "+str(flips)
  
