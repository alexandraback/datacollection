import math

primesf = open('primes.txt','r')
primes = []
IsPrime = [False]*15485864

for line in primesf:
    line = line.split(', ')
    IsPrime[int(line[1])] = True
    primes.append(int(line[1]))

#print("prime ok")

def isPrime(n):
    divisor = 0
    if (n<=15485863 and IsPrime[n]):
        return 0
    for i in primes:
        if (i>math.sqrt(n)):
            break
        if (n%i==0):
            divisor = i
            break;
    return divisor
    
def toBase(s,base):
    res = 0
    i=1
    for c in s:
        if(c=='1'):
            res+= (base**(len(s)-i))
        i+=1
    return res

____=int(input())
___=input()
n = int(___.split(' ')[0])
j = int(___.split(' ')[1])
printcount = 0
curr = (2**(n-1)) + 1
ub = 2**n
if n==1:
    curr=1
print("Case #1:")
while (printcount<j and curr<ub):
    ok = True
    s = "{0:b}".format(curr)
    value = [0]*11
    for i in range(2,11):
        basecurr = toBase(s,i)
        divisor = isPrime(basecurr)
        if divisor==0:
            ok = False
            break
        else:
            value[i]=divisor
    if (ok):        
        printcount+=1
        prints = s
        for i in range(2,11):
            prints+=' '+str(value[i])
        print(prints)
    curr+=2
printcount=0
