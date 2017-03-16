from math import *
T=int(input())
for i in range(T):
    N,J=map(int,input().split())
    print("Case #" + str(i+1) + ":")
    for j in range(2**(N-1)+1,2**N,2):
        if J == 0:
            break
        nb=9
        tab=[0]*9
        res=[0]*9
        a = 0
        while j!=0:
            for k in range(2,11):
                tab[k-2]+=j%2*k**a
            a+=1
            j//=2
        for d in range(2,1000):
            for k in range(9):
                if res[k]==0 and tab[k]%d==0:
                    res[k]=str(d)
                    nb-=1
            if nb == 0:
                break
        if nb == 0:
            print(str(tab[8]) + " " + " ".join(res))
            J-=1
