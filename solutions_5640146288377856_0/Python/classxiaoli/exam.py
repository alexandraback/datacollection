
def getscore(c1:int,c2:int,c3:int)->int:    
    n=int(c2/c3)
    res=c2-n*c3
    if res>0:
        return c1*(n+c3)
    else:
        return c1*(n+c3-1)
    
       

   
    
       
new=open("A-small-attempt0.in")

new1=open("output.txt","w")
n1=new.readline()
for i in range(int(n1)): 
    a=new.readline()
    [c1,c2,c3]=[int(j) for j in a.split()]
   
    score=getscore(c1,c2,c3)
    new1.write('Case #'+str(i+1)+': '+str(score)+'\n')     
                
                
    
 
    

        
     

