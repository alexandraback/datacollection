# for py3.3 (partically py2.7)

def time(func):
    def time_measuring_func(*args, **kwargs):
        import time
        t0 = time.time()
        result = func(*args, **kwargs)
        print('{}: {} seconds.'.format(func.__name__, time.time()-t0))
        return result
    return time_measuring_func


def primecheck(n):
    from math import sqrt
    if n<=1 or type(n)!=type(1):
        return 0
    elif n==2 or n==3:
        return 1
    elif n%2==0:
        return 0
    else:
        check=0
        for i in range(3,int(sqrt(n))+1,2):
            if n%i==0:
                check=1
                break
        if check==1:
            return 0
        else:
            return 1
    del(sqrt,i)


def prime_make(n):
    from math import sqrt
    l=[True for i in range(n+1)]
    for i in range(n+1):
        if not i%2:
            l[i]=False
    x=int(sqrt(n)+1)
    l[1]=False;l[2]=True
    for i in range(3,x,2):
        if l[i]:
            for j in range(2,int(n/i)+1):
                l[i*j]=False
        else:
            continue
    return [i for i in range(1,n+1) if l[i]]


def factoring(n):
    from math import sqrt
    primes=prime_make(int(n/2)+6)
    xl=[]
    if n==1:
        xl.append(1)
    elif n==2:
        xl.append(2)
    elif n==3:
        xl.append(3)
    for i in primes:
        while n%i==0:
            xl.append(i)
            n=n/i
    if xl==[]:
        xl.append(n)
    return xl


def pandigital_check(n,y=1):
    if type(n)==type("text"):
        n=int(n)
    checklst1=list(set(list(str(n))))
    checklst1.sort()
    checklst2=[]
    for i in range(len(str(n))):
        checklst2.append(str(i+1))
    if y==0:
        checklst2.remove(checklst2[-1])
        checklst2.append(str(0))
    checklst2.sort()
    if checklst1==checklst2:
        return 1
    else:
        return 0


def sum_numbers_expo(n,j=1):
    n=str(n)
    nlist=list(n)
    for i in range(len(nlist)):
        nlist[i]=int(nlist[i])**j
    return sum(nlist)


def sum_divisors(n):
    sum=0
    for i in range(1,n):
        if n%i==0:
            sum+=i
    return sum


def is_kaibun(n):
    if str(n)==str(n)[::-1]:
        return True
    else:
        return False


def how_many_divisors(n):
    y=len(str(n))
    xd={}
    i=2
    while n%i==0:
        if xd.has_key(i):
            xd[i]+=1
        else:
            xd[i]=1
        n=n/i
    i=3
    while n%i==0:
        if xd.has_key(i):
            xd[i]+=1
        else:
            xd[i]=1
        n=n/i
    i=1
    while i<long(n)*2:
        while n%(6*i-1)==0:
            if xd.has_key(6*i-1):
                xd[6*i-1]+=1
            else:
                xd[6*i-1]=1
            n=n/(6*i-1)
        while n%(6*i+1)==0:
            if xd.has_key(6*i+1):
                xd[6*i+1]+=1
            else:
                xd[6*i+1]=1
            n=n/(6*i+1)
        i+=1
    if xd.keys==[]:
        xd[i]=1
    return xd