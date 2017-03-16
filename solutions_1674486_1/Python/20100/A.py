
T=int(input())

for i in range(T):
    N=int(input())
    b=True
    tab=[]
    for j in range(1,N+1):
        L=input().split()
        for z in L[1:]:
            if int(z)>0:
                tab+=[(j,int(z))]
    r="No"
    for j in range(1,N+1):
        b=True
        t2=[False for z in range(N)]
        tt=[z for z in tab]
        t2[j-1]=True
        while b:
            b=False
            for z in tt:
                if t2[z[0]-1]==True and t2[z[1]-1]==False:
                    b=True
                    t2[z[1]-1]=True
                    tt.remove(z)
                else:
                    if t2[z[0]-1]==True and t2[z[1]-1]==True:
                        r="Yes"
                        break
        if r=="Yes":
            break
    print("Case #"+str(i+1)+": "+r)

