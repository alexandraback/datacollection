f = open("C-small-attempt4.in",'r')
#f = open("C-large.in",'r')

#quaternions are written as (-1)*(i)*(j)
quat ={'i':[0,1,0],'j':[0,0,1],'k':[0,1,1],'I':[1,1,0],'J':[1,0,1],'K':[1,1,1]}
def quadmul(A,B):
    return [(A[0]+B[0]+A[1]*B[1]+A[2]*B[2]+A[2]*B[1])%2,(A[1]+B[1])%2,(A[2]+B[2])%2]

def find(S, q):
    buf =[0,0,0]
    for i in range(len(S)):
        buf = quadmul(buf,quat[S[i]])
        if buf ==q:
            return i
    return -1

def evalu(S):
    buf =[0,0,0]
    for i in range(len(S)):
        buf = quadmul(buf,quat[S[i]])
    return buf


def qfastexp(q,n):
    buf = [0,0,0]
    while n>0:
        if n%2!=0:
            buf=quadmul(buf,q)
        q=quadmul(q,q)
        n=n//2
    return buf

#f=open("C-sample.in",'r')
output  = open("output.txt",'w')
cases =int(f.readline())
for case in range(1,cases+1):
    [L,X] =[int(j) for j in str.split(f.readline())]
    S=f.readline().split("\n")[0]
    print([L,X,len(S)])
    result =evalu(S)
    result =qfastexp(result,X)
    print(result)
    if result != [1,0,0]:
        ret="NO"
    else:
        rep =S*min(4,X)
        first = find(rep,[0,1,0])
        print(first)
        rep = (S[::-1]*min(4,X)).upper()
        last =find(rep,[1,1,1])
        print(last)
        ret = "YES" if  (first >=0) and (last >=0) and (first+last+2<L*X) else "NO"
    output.write("Case #"+str(case)+": "+str(ret)+"\n")
output.close()
f.close()
