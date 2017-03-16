new=open("C-large.in")
new1=open('output.txt','w')
t=new.readline()
matrix1=[[1,2,3,4],[2,1,4,3],[3,4,1,2],[4,3,2,1]]

matrix2=[[0,0,0,0],[0,1,0,1],[0,1,1,0],[0,0,1,1]]

for i in range(int(t)):
    [a,b]=new.readline().split()
    c=new.readline()
#    print(c)
    n=len(b)
    if n==1:
        num=int(b)
    else:
        num=(int(b[n-1])+int(b[n-2])*10)%4+8
   
    sum=1
    symbol=0
    for m in range(int(a)):
        sum0=sum
        k=ord(c[m])-ord('h')
        sum=matrix1[sum0-1][k]
        symbol=(matrix2[sum0-1][k]+symbol)%2
    
    goon=True
 #   print(sum,symbol)
    if sum==1 and symbol==0:
        goon=False
    elif sum==1 and symbol==1 and num%2==0:
        goon=False
    elif sum!=1 and num%4!=2:
        goon=False
        
    if goon==False:
        new1.write('Case #'+str(i+1)+': '+'NO'+'\n')
    
    else:
#        print('reach',i+1)
        sum=1
        symbol=0
        search_index=2
        iftrue=False
        for j in range(num):
            for m in range(int(a)): 
                k=ord(c[m])-ord('h')
                sum0=sum
                sum=matrix1[sum0-1][k]
                symbol=(matrix2[sum0-1][k]+symbol)%2
#                print(search_index,sum,symbol,k)
                if sum==search_index and symbol==0:
                    if search_index!=4:
                        
                        search_index+=1
                        sum=1
                        symbol=0
                    else:
                        new1.write('Case #'+str(i+1)+': '+'YES'+'\n')
                        iftrue=True
                        break
            if iftrue==True:
                break 
        if iftrue==False: 
            new1.write('Case #'+str(i+1)+': '+'NO'+'\n')      
                
                
                      
                
        
        
        
     
    
        
             
    
