f = open('testcase', 'r')
f1 = open('ans', 'w')
tc=int(f.readline())
#print tc
for i in range(tc):
    nver=[1 for j in range(10)]
    k,c,s=map(int,f.readline().split())   
    
    
    if(k==1 or c==1):
        ans=' '.join(str(i+1) for i in range(k))
    
    else:
        ans=' '.join(str(i+1) for i in range(1,k))
    if((c==1 and k>s)or s<k-1):
        ans='IMPOSSIBLE'   
       
    f1.write('Case #'+str(i+1)+': '+ans+'\n')

        
