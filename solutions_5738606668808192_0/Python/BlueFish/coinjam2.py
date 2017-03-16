# Python 2.5.3

def disclog(n,b):
 out=0
 while n>=b: n/=b; out+=1
 return out

def bin(n):
 out=''
 while n: out+=str(n%2); n/=2
 return out[::-1]

def solve(N,J):
 m=[]; i=3
 while len(m)<J:
  compl=2**(N-1-disclog(i,2))
  if (compl*i)&i==0: m.append((i*(compl+1),i))
  i+=2
 out=''
 for num,fac in m:
  binnum=bin(num); binfac=bin(fac); out+=binnum
  for base in range(2,11):
   basenum=int(binnum,base)
   basefac=int(binfac,base)
   try: assert basenum%basefac==0
   except: print base,binnum,basenum,binfac,basefac,basenum%basefac
   out+=' %i'%basefac
  out+='\r\n'
 return out

inp=file('C-small-attempt1.in','rb+'); out=file('C-small-attempt1.out','wb+')

T=int(inp.readline().strip())

for i in range(1,T+1):
 out.write('Case #%i:\r\n'%i)
 N,J=[int(s) for s in inp.readline().strip().split(' ')]
 out.write(solve(N,J))