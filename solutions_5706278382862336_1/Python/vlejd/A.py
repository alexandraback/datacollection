def nsd(a,b):
   if(a==0): return b
   if(b>=a): return nsd(b%a,a)
   return nsd(b,a) 
   

a = int(raw_input())
for t in xrange(a):
   print "Case #"+str(t+1) + ":",
   inp = raw_input().split('/')
   p = int(inp[0])
   q = int(inp[1])
   ns = nsd(p,q)
   q/=ns
   p/=ns
   ok = False
   for i in xrange(100):
      if( 2**i==q):
         ok=True
         break
   if( (not ok ) or p>q):
      print "impossible"
      continue
   kolka = 0
   while p<q:
      kolka+=1
      q/=2
   print kolka