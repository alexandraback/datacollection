f = open('testcase', 'r')
f1 = open('ans', 'w')
tc=int(f.readline())
#print tc
for i in range(tc): 
    ans=0   
    n=str(f.readline())
    le= len(n)
    co=0
    if(n[0]=='+'):
        fl=1 
    elif(n[0]=='-'):
        fl=0            
    for k in range(1,le):
        if(fl==1):
            if(n[k]=='-'):
                co+=1
                fl=0
        else:
            if(n[k]=='+'):
                co+=1
                fl=1  
    if(fl==0):
        co+=1
    ans=co
    f1.write('Case #'+str(i+1)+': '+str(ans)+'\n')
