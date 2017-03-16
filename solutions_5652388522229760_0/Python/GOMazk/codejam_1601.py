import sys
caseN=int(input())
for i in range(1,caseN+1):
    inp=int(input())
    if(inp==0):
        print("Case #%d: INSOMNIA"%(i))
        continue
    
    digset=set()
    j=0
    while(1):
        j+=1
        num=inp*j
        digset.add(num%10)
        k=1
        while(num//(10**k)>0):
            digset.add( (num//(10**k))%10 )
            k+=1
        if(len(list(digset))==10):
            print("Case #%d: %d"%(i,num))
            break
