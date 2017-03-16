def cal(st,ed,K):
    c=1
    res=0
    for i in range(st,ed+1,1):
        res = res + c*(i-1)
        c = c*K
    return res + 1

T = int(input())
for i in range(T):
    K,C,S = input().split()
    K=int(K)
    C=int(C)
    S=int(S)
    print("Case #",i+1,":",sep='',end=' ')
    if (K>S*C):
        print("IMPOSSIBLE")
        continue
    a=0
    while a<K :
        if(a+C>K):
            print(cal(a+1,K,K),end=' ')
        else:
            print(cal(a+1,a+C,K),end=' ')
        a = a+C
    print()
