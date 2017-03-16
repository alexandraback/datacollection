


T = int(input())
for n in range(T):
    B,M = input().split()
    B=int(B)
    M=int(M)
    A=[]
    for i in range(B+1):
        A.append([0]*51)
    print("Case #",n+1,":",sep='',end=' ')
    if(M>2**(B-2)):
        print("IMPOSSIBLE")
        continue
    print("POSSIBLE")
    for i in range(B):
        for j in range(B):
            if(i<j):
                A[i][j]=1
    for i in range(B-1):
        if(M==2**(B-2)):
            break
        if (i==0):
            A[i][B-1]=0
            continue
        if(M%2==0):
            A[i][B-1]=0
        else:
            M=M-1
        M=int(M/2)




    for i in range(B):
        for j in range(B):
            print(A[i][j],sep='',end='')
        print()

