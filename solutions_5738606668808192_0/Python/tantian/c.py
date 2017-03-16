import primesieve

def isprime(x):
    it=primesieve.Iterator()
    it.skipto(x-1)
    return x==it.next_prime()

def change(x, p):
    y=0
    for i in xrange(15,-1,-1):
        y*=p
        if (x&(1<<i))>0:
            y+=1
    return y

def check(x):
    for i in xrange(2,11,1):
        if isprime(change(x,i)):
            return False
    return True

def output(x):
    print bin(x)[2:],
    for i in xrange(2,11,1):
        y=change(x,i)
        for j in xrange(2,y,1):
            if y%j==0:
                print j,
                break
    print

x=(1<<15)+1
tt=0

while True:
    if check(x):
        output(x)
        tt=tt+1
    if tt==500:
        break
    x+=2
