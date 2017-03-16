
T=int(input())
for n in range(T):
    J,P,S,K=input().split()
    J=int(J)
    P=int(P)
    S=int(S)
    K=int(K)
    if(S>K):
        S=K
    print("Case #",n+1,":",sep='',end=' ')
    print(J*P*S)
    for j in range(J):
        for p in range(P):
            for s in range(S):
                print(j+1,p+1,s+1)
