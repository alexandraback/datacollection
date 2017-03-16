order=[(i%10+1,(i/10)%10+1,(i/100)%10+1) for i in range(1000)]
order.sort(key = lambda (x,y,z): ((x+y+z,x+y,x)))

def solve(J,P,S,K):
 order2=[]
 for j,p,s in order:
  if j<=J and p<=P and s<=S: order2.append((j,p,s))
 JP={}
 for j in range(1,J+1):
  for p in range(1,P+1): JP[(j,p)]=0
 JS={}
 for j in range(1,J+1):
  for s in range(1,S+1): JS[(j,s)]=0
 PS={}
 for p in range(1,P+1):
  for s in range(1,S+1): PS[(p,s)]=0
 valid=[]
 for j,p,s in order2:
  if JP[(j,p)]<K and JS[(j,s)]<K and PS[(p,s)]<K:
   valid.append((j,p,s))
   JP[(j,p)]+=1 ; JS[(j,s)]+=1 ; PS[(p,s)]+=1
 return valid

inp=file('C-small-attempt1.in','rb+'); out=file('C-small-attempt1.out','wb+')

T=int(inp.readline().strip())

for i in range(1,T+1):
 J,P,S,K=[int(s) for s in inp.readline().strip().split(' ')]
 sol=solve(J,P,S,K)
 outline='Case #%i: %i'%(i,len(sol))
 for l in sol: outline+='\r\n'+' '.join([str(n) for n in l])
 print outline
 out.write(outline+'\r\n')