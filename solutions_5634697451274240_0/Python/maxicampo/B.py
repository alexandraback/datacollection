f=open("B-small.in","r")
g=open("pancakes.out","w")

#flips the first n pancakes
def flip(P,n):
  if n > len(P):
    return "Not enough pancakes!"
  else:
    A = P[0:n]
    B = P[n:]
    A = [-x for x in A[::-1]]
    return A+B
  
T = int(f.readline())

for i in range(0,T):
  P = [x+"1" for x in f.readline()]
  P = map(int,P[:-1])
  N = len(P)
  K = 0
  while -1 in P:
    m = N
    auxm = P[m-1]
    while auxm == 1:
      m-=1
      auxm = P[m-1] #last minus is in position m of the list (index m-1)

    p = 0
    auxp = P[p]
    while auxp == 1:
      p+=1
      auxp = P[p] #biggest block of plus signs starting from the beginning is of size p 

    if p != 0:
      P = flip(P,p)
      K+=1
    
    P = flip(P,m)
    K+=1

  g.write("Case #"+str(i+1)+": "+str(K)+"\n")

  
  
  
