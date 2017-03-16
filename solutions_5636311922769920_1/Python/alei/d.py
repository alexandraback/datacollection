import sys
sys.stdin=open("dl.in","r")
sys.stdout=open("dl.out","w")
t=int(sys.stdin.readline())
def solve(k,c,s,t):
   if c==1:
      if s<k: sys.stdout.write("Case #{0}: IMPOSSIBLE\n".format(tt))
      else: sys.stdout.write("Case #{0}:{1}\n".format(tt,''.join([" "+str(x+1) for x in range(k)])))
      return 0
   if k==1:
      sys.stdout.write("Case #{0}: 1\n".format(tt))
      return
   kc=k**c
   maxi=-1
   for l in range(k-1,0,-1):
      for g in range(1,k):
         L,G=l,g
         for i in range(c-1):
            G=L*g+k*G
            L=L*l
            if L+G>kc:break
         if L+G==kc:maxi=max(maxi,l)
   if maxi==-1: 
      sys.stdout.write("Case #{0}: 1\n".format(tt))
      return
   if s<maxi:sys.stdout.write("Case #{0}: IMPOSSIBLE\n".format(tt))
   else: sys.stdout.write("Case #{0}:{1}\n".format(tt,''.join([" "+str(x) for x in range(2,maxi+2)])))

for tt in range(1,t+1):
   k,c,s=[long(x) for x in sys.stdin.readline().split()] 
   solve(k,c,s,t) 
