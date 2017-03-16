
def getscore(c1:int,c2:int,c3:int,b:str,c:str)->float:    
    dict={}
    for i in range(c1):
        if b[i] not in dict:
            dict[b[i]]=1
        else:
            dict[b[i]]+=1
    
    for j in range(c2):
        if c[j] not in dict:
            return 0.0
        
    a0=c[0]  
    cirnum=c2 
    ifupdate=True 
    for j in range(1,c2):
        if c[j]==a0:
            for k in range(j,c2):
                if c[k]!=c[k-j]:
                    ifupdate=False
                    break
            if ifupdate==True:
                cirnum=j
        if cirnum!=c2:
            break
    n=int((c3-c2)/cirnum)+1
 
    p=0.0
    p0=1.0
    for j in range(c2):
        p0=p0*dict[c[j]]/c1
    p00=p0
    p+=1-pow(1-p0,c3-c2+1)

    for i in range(1,n):
        for j in range(cirnum):
            p0=p0*dict[c[j]]/c1
        p+=1-pow(1-p0,c3-c2-cirnum*i+1)
        if c3>=i*(c2+1)+c2:
            p+=1-pow(1-pow(p00,i+1),c3-i*(c2+1)-c2+1)
            
  
  
    return float(n)-p
    
         
        
        
        
        
    
       

   
    
       
new=open("B-small-attempt2.in")

new1=open("output.txt","w")
n1=new.readline()
for i in range(int(n1)): 
    a=new.readline()
    b=new.readline()
    c=new.readline()
    [c1,c2,c3]=[int(j) for j in a.split()]
    score=getscore(c1,c2,c3,b,c)
    score1=round(score,7)
    new1.write('Case #'+str(i+1)+': '+str(score1)+'\n')     
                
                
    
 
    

        
     

