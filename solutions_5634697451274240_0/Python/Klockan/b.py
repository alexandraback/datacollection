for xx in range(int(raw_input())):
  s=raw_input()+"+"
  ans=0
  for i in range(len(s)-1):
    ans+=s[i]!=s[i+1]
  print "Case #%d:"%(xx+1),ans

