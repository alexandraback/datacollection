f=open("C.in","r")
g=open("sets2.out","w")
import fractions

f.readline()
f.readline()
g.write("Case #1:\n")

for j in range(0,8000):
  L = map(int,f.readline().split( ))
  ans = ''
  ans2 = ''
  for i in range(0,12):
    for j in range(0,12):
      if  1 < fractions.gcd(L[i],L[j]) < 9 and len(ans) < 12:
        ans = ans + str(fractions.gcd(L[i],L[j]))
        
  if len(ans) == 12:
    g.write(ans+"\n")
  else:
    for w in range(0,12-len(ans)): 
      ans2 = ans2 + '2'
    ans = ans + ans2
    g.write(ans+"\n")
