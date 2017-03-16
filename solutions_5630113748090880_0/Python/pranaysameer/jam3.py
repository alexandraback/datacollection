n=int(raw_input())
for j in range(0,n):
    k=int(raw_input())
    arr=[]
    for i in range(0,2*k-1):
        x=raw_input().split()
        for i in x:
            arr.append(int(i))
    arr.sort()
    k=len(arr)
    sol=[]
    i=0
    while(i<k-1):
        if arr[i]!=arr[i+1]:
            sol.append(arr[i])
            i-=1
        i+=2
    if(arr[k-1]!=arr[k-2]):
        sol.append(arr[k-1])
    stri=""
    for i in sol:
        stri=stri+str(i)+" "
    print "Case #"+str(j+1)+": "+stri
            
        
        
        
