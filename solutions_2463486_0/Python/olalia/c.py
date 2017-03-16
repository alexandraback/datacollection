import fileinput
import numpy
import math

tc=0
T=0

'''
def nextpal(int k, int k1):
    k2=k
    for i in range(k1):
        k3=(k2%(10**(i+1)))/10**i
        if (k3>1):
            k2+=(10-k3)*10**i
    h=0
    if (k2>=10**k1):
        return 0;
    for i in range(k1):
        h+=k2%10*2**i
        k2/=10
    nen=0
    for i in range(k1/2, k1):
        if ((1<<i)&h!=0):
            nen+=1
    while(nen>3):
'''        
   
 

twoers=[2]
for i in range(2,101):
    if (i%2==1):
        u=10**(i-1)+1+2*10**((i-1)/2)
        twoers.append(u)
        for j in range((i-3)/2):
            twoers.append(u+10**((i+1)/2+j)+10**((i-3)/2-j))
    
    twoers.append(2*10**(i-1)+2)
    if (i%2==1):
        twoers.append(2*10**(i-1)+2+10**((i-1)/2))

oners=[1, 11]


'''
, 101, 111, 1001, 1111, 10001, 10101, 11011, 11111, 100001, 101101, 110011, 111111, 1000001, 1001001, 1010101, 1011101, 1100011, 1101011, 1110111, 1111111]
'''


for i in range(3, 53):
    m=i/2-1
    u=10**(i-1)+1
    for j1 in range(-1, m):
        for j2 in range(-2, j1):
            for j3 in range(-3, j2):
                v=u
                if (j2==-2 and j1!=-1):
                    continue
                if (j3<-1 and j2-j3!=1):
                    continue
                if (j1>-1):
                    v+=10**((i+1)/2+j1)+10**(i/2-1-j1)
                if (j2>-1):
                    v+=10**((i+1)/2+j2)+10**(i/2-1-j2)
                if (j3>-1):
                    v+=10**((i+1)/2+j3)+10**(i/2-1-j3)
                          
                oners.append(v)
                if (i%2==1):
                    oners.append(v+10**(i/2))
                                              

for line in fileinput.input():
    if (tc==0):
        T=int(line)
        tc+=1
    else:
        words=line.split()
        A=int(words[0])
        B=int(words[1])
        a=int(math.ceil(math.sqrt(A)))
        b=int(math.floor(math.sqrt(B)))
        ans=0
        if (a<=3 and b>=3):
            ans+=1
        a1=-1 
        b1=len(twoers)-1
        c1=(a1+b1+1)/2
        while (b1!=c1):
            if (a<=twoers[c1]):
                b1=c1
            else:
                a1=c1
            c1=(a1+b1+1)/2
        a1=-1
        b1=len(twoers)
        c2=(a1+b1)/2
        while(a1!=c2):
            if (b<twoers[c2]):
                b1=c2
            else:
                a1=c2
            c2=(a1+b1)/2
        ans+=c2-c1+1
        '''
        a1=1+int(math.floor(math.log10(a)))
        b1=1+int(math.floor(math.log10(b)))
        
        for i in range(a1, b1+1):
            
            j=i/2-1
            
            if (j>-1):
                c=1
                c+=j
                c+=j*(j-1)/2
                c+=j*(j-1)*(j-2)/2/3
                if (i%2==1):
                    c*=2
                ans+=c
        '''
        a1=-1 
        b1=len(oners)-1
        c1=(a1+b1+1)/2
        while (b1!=c1):
            if (a<=oners[c1]):
                b1=c1
            else:
                a1=c1
            c1=(a1+b1+1)/2
        a1=-1
        b1=len(oners)
        c2=(a1+b1)/2
        while(a1!=c2):
            if (b<oners[c2]):
                b1=c2
            else:
                a1=c2
            c2=(a1+b1)/2
        ans+=c2-c1+1
        
            


        print "Case #"+str(tc)+": "+str(ans)
        tc+=1
    

