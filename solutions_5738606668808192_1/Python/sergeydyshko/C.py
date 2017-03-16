CurrentPathIn = "input.txt"
CurrentPathOut = "output"

fr = open(CurrentPathIn,"r")
fw = open(CurrentPathOut,"w")

import math
import random

#stackoverflow code
def primes_upto(limit):
    prime = [True] * limit
    for n in range(2, limit):
        if prime[n]:
            yield n # n is a prime
            for c in range(n*n, limit, n):
                prime[c] = False
#end of stackoverflow code
primes = list(primes_upto(10000))

def divisor(n):
    for p in primes:
        if n%p==0:
            return p
    return 0
#    for i in range(2,math.ceil(math.sqrt(n))):
#        if n%i==0:
#            return i
#    return 0

def sample(i, n):
    s = bin(i)
    s = s[2:]
    s = '0'*(n - len(s)) + s
    return '1'+s+'1'

def tobase(s, base):
    res = 0
    for i in range(len(s)):
        if s[i]=='0':
            pass
        else:
            res+=1
        if (i!=len(s)-1):
            res*=base
    return res

def isJam(s):
    divs = {}
    for base in range(2,11):
        t = tobase(s, base)
        x = divisor(t)
        if x==0:
            return [False]
        else:
            divs[base] = x
    return [True,divs]

def foo(N, J):
    res = {}
    i = -1
    while len(res)<J:
        i+=1
#        i = random.randint(0,2**(N-2)-1)
        s = sample(i, N-2)
        x = isJam(s)
        if x[0]:
            res[s] = x[1]
            print(len(res))
    return res
        
T = int(fr.readline())
for t in range(T):
    N,J = fr.readline().split()
    N, J = int(N), int(J)
    res = foo(N,J)
    
    fw.write("Case #1:\n")
    for k in res:
        s = ""
        for k1 in res[k]:
            s+=" "+str(res[k][k1])
        fw.write(k+s+"\n")

fr.close()
fw.close()
