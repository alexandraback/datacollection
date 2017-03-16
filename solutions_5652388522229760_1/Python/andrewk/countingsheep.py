import numpy

for case in range(1,int(input())+1):
    M=[False]*10
    n=int(input())
    if n > 0:
        i=1
        while not all(M):
            for s in str(i*n):
                M[int(s)]=True
            i+=1
        i-=1
        res = str(i*n)
    else:
        res = "INSOMNIA"
    print("Case #"+str(case)+": "+res)
        
