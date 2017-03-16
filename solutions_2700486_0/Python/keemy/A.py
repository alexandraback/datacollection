from math import *

fu=open('B.in','r')
pro=(fu)

out=''


N=int(pro.readline())

#memo={}
def prob(numD,X,Y):
#    if (numD,X,Y) in memo:
#        return memo( (numD,X,Y))
    n = floor((sqrt(8*numD+1)+1)/4)
    #import pdb; pdb.set_trace()
    
    if (X+Y)//2 <n:
        return 1.0

    if (X+Y)//2>n:
        print "fk"
        return 0.0

    if (X+Y)//2 ==n:
        temp= numD-(2*n**2-n)
    if X==0:
        return 0.0
    if temp<Y:
        return 0.0
    if (temp-(2*n+1))>=Y:
        return 1.0
   
    sum1=0
    if temp>2*n:
        lul=int(temp-2*n)
        temp=temp- 2*(temp-2*n)
        for i in range(Y-lul+1):
            sum1+= nCk(temp,i)
        return 1-sum1/(2**(temp))
    else:
        for i in range(Y+1):
            sum1+= nCk(temp,i)
        return 1-sum1/(2**(temp))
    
    

    
def nCk(n,k):
    return factorial(n)//(factorial(n-k)*factorial(k))



for n in range(N):
    rawr= pro.readline().split()

    numD= int(rawr[0])
    X =int(rawr[1])
    Y= int(rawr[2])

    out=out + 'Case #%d: '%(n+1) + str(prob(numD,abs(X),Y)) + '\n'

print out

f=open('output','w')
f.write(out)
f.close()
fu.close()


