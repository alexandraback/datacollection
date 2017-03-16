import math

def ToStr(n):
    s=[]
    while(n!=0):
        s.append(n%2)
        n/=2
        n=int(n)
    if(len(s)==0):
        s.append(0)
    ret=''
    while(len(s)!=0):
        ret+=str(s.pop())
    return ret

def isNotPrime(n):
    if(n<2):
        return True
    ed=int(math.sqrt(n))
    for i in range(2,ed+1):
        if(n%i==0):
            return True
        if(i>10000000):
            return False
    return False

def jinzhi(n,k):
    s=[]
    while(n!=0):
        s.append(n%2)
        n/=2
        n=int(n)
    if(len(s)==0):
        s.append(0)
    ret=0
    while(len(s)!=0):
        tmp=s.pop()
        ret+=tmp*(k**len(s));
    return ret

T=1
N=32
J=500
st=1+2**(N-1)
ed=st
ans=[]
for i in range(N-1)[1:]:
    ed+=2**i
cnt=0
file=open('outV2.out','w')
file.write("Case #1:\n")

for i in range(st,ed+1,2):
    f=True
    for j in range(2,11):
        tmp=jinzhi(i,j)
        if(isNotPrime(tmp)==False):
           f=False
           break
    if(f):  
        tt = {}
        tt['val']=ToStr(i)
        tt['arr']=[]
        for j in range(2,11):
            tmp=jinzhi(i,j)
            ed1=int(math.sqrt(tmp))
            for k in range(2,ed1+1):
                if(tmp%k==0):
                    tt['arr'].append(k)
                    break
        cnt=cnt+1
        ans.append(tt)
        print(str(cnt)+':'+str(tt))
        if(cnt==J):
            break

for i in range(0,cnt):
    out="%s"%(ans[i]['val'])
    for j in range(0,9):
        out=out+" %d"%(ans[i]['arr'][j])
    out=out+'\n'
    file.write(out)