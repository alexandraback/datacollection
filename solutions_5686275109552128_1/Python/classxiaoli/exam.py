new=open("B-large.in")

new1=open("output.txt","w")
n1=new.readline()
for i in range(int(n1)):
   
    a=new.readline()
    b=new.readline()
    c=[int(j) for j in b.split()]
    num=int(a)
   
    k=max(c)
    c1=sorted(c)
 #   print(c1)
    time_index=num-1
    if k<=3:
        time=k
    
    else:
        n=2
        time=k
        stop=k-2
        critic=int((k+1)/2)
        search_index=0
       
        while n<=stop:
            while search_index<num-1 and c1[search_index]<=n :
                search_index+=1
            min_num=n
            for j in range(search_index,num):
                
                min_num+=int((c1[j]-1)/n)
  #          print(min_num,n)
            if time>min_num:
                time=min_num
                time_index=n
            if n>=critic:
                n=c1[search_index]
            else:
                n+=1
   # print(time_index)
    new1.write('Case #'+str(i+1)+': '+str(time)+'\n')        
                
                
    
 
    

        
     

