f=open("A-large.in","r")
g=open("sleep.out","w")

T = int(f.readline())

for i in range(0,T):

  N = int(f.readline())
  L = []
  prev = 0
  last = N
  strlast = str(N)
  if N == 0:
    ans = "INSOMNIA"
  else:
    while len(L) < 10:
      for x in strlast:
        if x not in L:
          L.append(x)
      prev = prev + N
      last = last+N
      strlast = str(last)
    ans = str(prev)



  g.write("Case #"+str(i+1)+": "+ans+"\n")

  
  
  
