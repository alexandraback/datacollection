           
t=input()
for i in range(0,t):
    a,n=raw_input().split(' ')
    n=int(n)
    a=int(a)
    moto=[]
    temp = raw_input()
    moto = map(int, temp.split())
    moto.sort()
    power=a
    
    correction=0
    found_correction=[]
    k=0
    found=False
    for num in moto:
        k+=1        
        if found == True:
            break        
        if power<=num:
            found_correction.append(correction+len(moto)-k+1)
            while power<=num:
                new=power-1
                if  new == 0:
                    correction+=len(moto)-k+1                
                    found=True
                    break       
                else:     
                    correction+=1
                    power+=(new)
            power+=num        
        else:
            power+=num
            
    found_correction.append(correction)    
    print "Case #{0}: {1}".format(i+1,min(found_correction)) 