f=open("A-large.in","r")
g=open("elflarge.out","w")

L = [2**n for n in range(0,40)]

def gcd(a,b):
 if a < b: a,b = b,a
 while b:
  a,b = b,a%b
 return a


T = int(f.readline())

for i in range(0,T):
  [P,Q] = map(int,f.readline().split('/'))
  d = gcd(P,Q)
  A = P/d
  B = Q/d

  y = 0
  aux = 2
  while aux < A:
    y += 1
    aux = 2*aux
    
  if B not in L:
    ans = 'impossible'
  else:
    x = L.index(B)
    ans = str(x-y)
  
  g.write("Case #"+str(i+1)+": "+ans+"\n")

  
  
  
