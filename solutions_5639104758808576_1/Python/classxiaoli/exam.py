new=open("A-large.in")

new1=open("output3.txt","w")
n1=new.readline()
for i in range(int(n1)):
    a=new.readline()
    [a1,a2]=a.split()
    extra=0
    num=0
    for j in range(int(a1)):
        value=int(a2[j])
        if value==0:
            if num==0:
                extra+=1
            else:
                num-=1    
        else:          
            num+=value-1
    new1.write('Case #'+str(i+1)+': '+str(extra)+'\n')
        
     

