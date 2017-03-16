#T = int (raw_input())
def getFactors(a):
    rv=[]
    l=2
    while True:
        found=False
        for i in range(l,51):
            if (a%i)==0:
                rv.append(i) 
                l=i
                a=a/i
                found=True
                break
        if found==False:
            rv.append(a)
            break;
    return sorted(rv)
        

T=int(raw_input())
for t in range(0,T):
    
    ulaz=raw_input().split()
    B,M=int(ulaz[0]), int(ulaz[1])
    matrica=[]
    for i in range(0,B):
        matrica.append(list())
        for j in range(0,B):
            matrica[i].append(0)

    S=[]
    for i in range(0,B):
        S.append(0)
    S[B-1]=1
    #print "start"
    index = B-2
    while True:
        if index<0:
            break
        for a in range(index+1,B):
            if S[index]+S[a]<=M:
                S[index]+=S[a]
                matrica[index][a]=1
        
        index=index-1
        if index<0:
            break;
    ok = False
    if S[0]==M:
        
        ok = True

    if ok:
        
        print "Case #"+str(t+1)+": POSSIBLE"
        for k in range(0,B):
            rv=""
            for z in matrica[k]:
                rv+=(str(z))
            print rv
            
    else:
        print "Case #"+str(t+1)+": IMPOSSIBLE"

    
            
        
              
        
#print getFactors(11234)          
#for t in range(0,T):
#    ulaz = raw_input().split()
 #   B,M = ulaz[0],ulaz[1]
    

    
