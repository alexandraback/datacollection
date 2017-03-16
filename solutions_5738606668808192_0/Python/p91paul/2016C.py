from math import gcd
from random import randint

def st(n):
    t = n-1
    s = 0
    while t % 2 == 0:
        t = int(t/2)
        s += 1
    return s,t

def pseudoprime(n,s,t,b):
    if abs(pow(b,t,n)) == 1: return True
    for r in range(s):
        if abs(pow(b,2**r*t,n)) == -1: return True
    return False

def nonprime(n):
    s,t = st(n)
    for _ in range(10):
        b = randint(2,n-1)
        #print("nonprime: n %d   b %d   gcd %d   t %d   pow(b,t,n) %d"%(n,b,gcd(n,b),tn,pow(b,tn,n)))
        if gcd(n,b) > 1 and not pseudoprime(n,s,t,b): return True
    return False

def divisor(n):
    for i in range(2,n):
        if n%i == 0: return i
    raise Exception("Was %d prime??"%n)

def randbin(N):
    n = [1]*N
    for i in range(1, N-1):
        n[i] = randint(0,1)
    return tuple(n)

def convert(digits, base):
    n = 0
    for d in digits:
        n = n*base + d
    #print(digits, base, n)
    return n

input() #skip first line
N, J = [int(x) for x in input().split(" ")]
print("Case #1:")
found = set()
while J > 0:
    digits = randbin(N)
    if (digits in found): continue
    allbase = [convert(digits, base) for base in range(2,11)]
    if False in [nonprime(n) for n in allbase]:
        continue
    else:
        print("%s %s"%("".join([str(d) for d in digits]), " ".join([str(divisor(n)) for n in allbase])))
        J -= 1
        found.add(digits)

