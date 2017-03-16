T=int(raw_input())
for i in range(T):
    N=int(raw_input())
    if N==0:
        print "Case #%d: INSOMNIA" %(i+1)
    else:
        cnt=[0 for j in range(10)]
        filledNum=0
        for r in range(1,1000000):
            n=r*N
            while n!=0:
                if cnt[n%10]==0:
                    filledNum+=1
                    cnt[n%10]+=1
                n/=10
            if filledNum==10:
                print "Case #%d: %d" %(i+1,r*N)
                break
            
                
