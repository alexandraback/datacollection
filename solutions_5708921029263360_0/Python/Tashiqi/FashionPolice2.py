T=int(input())
tab=[]
def test(i,j,n,v,m1,m2,m3,K,res):
    if j==0:
        return True
    elif n-i<j:
        return False
    elif test(i+1,j,n,v,m1,m2,m3,K,res):
        return True
    elif m1[(v[i][0],v[i][1])]<K and m2[(v[i][0],v[i][2])]<K and m3[(v[i][1],v[i][2])]<K:
        m1[(v[i][0],v[i][1])]+=1
        m2[(v[i][0],v[i][2])]+=1
        m3[(v[i][1],v[i][2])]+=1
        if test(i+1,j-1,n,v,m1,m2,m3,K,res):
            res += [str(v[i][0]+1) + " " + str(v[i][1]+1) + " " + str(v[i][2]+1)]
            return True
        m1[(v[i][0],v[i][1])]-=1
        m2[(v[i][0],v[i][2])]-=1
        m3[(v[i][1],v[i][2])]-=1
    else:
        return False
        

for t in range(T):
    J,P,S,K=map(int,input().split())
    n=J*P*S
    v=[(j,p,s) for j in range(J) for p in range(P) for s in range(S)]
    for j in range(n,-1,-1):
        m1={(j,p):0 for j in range(J) for p in range(P)}
        m2={(j,s):0 for j in range(J) for s in range(S)}
        m3={(p,s):0 for p in range(P) for s in range(S)}
        res = []
        if test(0,j,n,v,m1,m2,m3,K,res):
            print("Case #" +str(t+1) + ":",j)
            print("\n".join(res))
            break
