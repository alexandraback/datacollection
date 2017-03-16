from math import *
primes = [2,3]
ma = 1<<18
def precump():
    for i in range(3,ma,2):
        b = True
        for j in primes:
            if j*j > i:
                break
            if i % j == 0:
                b = False
                break
        if b:
            primes.append(i)

def div(i):
    for j in primes:
        if j >= i:
            break
        if i % j == 0:
            return j
    return 0

def toB(i,b):
    r = 0
    m = 1
    while i > 0 :
        r += m*(1&i)
        i = i>>1
        m *= b
    return r

precump()
t,j,n = map(int,raw_input().split())
print("Case #1:\n")
f = (1<<(j-1))+1
while(n):
    d = map(div,[toB(f,i) for i in range(2,10)])
    b = True
    for i in d:
        if i == 0:
            b = False
            break;
    if b:
        print(bin(f)[2:] + " " + " ".join(map(str,d)))
        n-=1
    f+=2

