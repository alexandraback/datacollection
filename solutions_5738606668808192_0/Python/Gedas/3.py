import time

##def uberPrimes():
##    primeList=open("D:\documents\stuff\progs\euler\primes7.csv","r")
##    b=str.split(primeList.readline()[:-1],",")
##    primeList.close()
##    return [int(x) for x in b]

##primes=uberPrimes() #the fastest way to generate primes :P
primes=[2,3,5,7,11] #because it actually does not matter...
print("Primes loaded")
time.clock()

def qnp(n):
##    if n<=primes[-1]:
##        if n in primes:
##            return False
##        else:
##            return fdiv(n)
    for i in primes:
        if n%i==0: return i
    return False

def fdiv(n):
    for i in primes:
        if n%i==0: return i
    print("Such fail, much wow")

def solve(n):
    n,j=map(int,n)
    sol=[]
    for i in range(2**(n-1)+1,2**n,2):
        num=bin(i)[2:]
        good=True
        divs=[]
        for m in range(2,11):
            divs.append(qnp(int(num,m)))
            if not divs[-1]:
                good=False
                break
        if good:
##            for m in range(2,11):
##                divs.append(fdiv(int(num,m)))
            sol.append(' '.join(map(str,[num,]+divs)))
            print('.',end='')
            if len(sol)==j:
                return '\n'.join(sol)
    print("Did not find enough :(")
            
    

inp=open("C-small-attempt0.in")
inp.readline() #trusting all the lines in input are important
out=open("3sa.txt","w")
case=1
for n in inp:
    out.write("Case #"+str(case)+":\n"+str(solve(n.split()))+"\n")
    case+=1
inp.close()
out.close()
print('\n'+str(time.clock()))

