f = open('testcase', 'r')
f1 = open('ans', 'w')
tc=int(f.readline())
#print tc
for i in range(tc):
    nver=[1 for j in range(10)]
    n=int(f.readline())
    #print n
    ans=0
    if(n==0):
        ans="INSOMNIA"
    else:
        k=0
        while(True):
            k+=1 
            res=n*k;  
            print res          
            tem=res
            while(tem>0):
                d=tem%10
                nver[d]=0
                tem=tem/10               
            if(nver.count(1)==0):
                ans=res
                break;                                
        if(ans==0):
            ans="INSOMNIA"
    f1.write('Case #'+str(i+1)+': '+str(ans)+'\n')

        