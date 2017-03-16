from math import ceil,sqrt

pims=[]
def prime(res):
    ub=10000
    for i in range(2,ub):
        if(res%i==0):
            return i;   
    return -1; 
        


n=32-1
j=500
decb= (2 ** n)+1
#primes_216()
#print pims
f1 = open('ans', 'w')
nver=[1 for k in range(10)]
val=[0 for i in range(n+1)]
val[0]=1
val[n]=1
f1.write('Case #1:\n')
co=0
l=0
ulb= 2 ** n-2
while(co < j and l<ulb):
    #print co
    di=[]
    f=1    
    
    for b in range(2,11):
        res=0
        for i in val:
            res=res*b+i    
        d=prime(res)        
        if(d==-1):
            f=0
            break
        else:
            di.append(d)

    if(f==0):  
        print 'aaa'  
        
        
    else:
        st=''
        r1=''
        st = ''.join(str(p) for p in val)
        r1= ' '.join(str(p) for p in di)
        f1.write(str(st)+' '+r1+'\n')
        #print str(st)+' '+r1
        co+=1
        print co
    decb+=2
    b1=bin(decb) 
    print b1    
    for i in range(n):
        val[i]=int(b1[i+2])   
            
    #print val
   

    
    