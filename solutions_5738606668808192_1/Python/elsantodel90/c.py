import sys
import random

#rabin miller

def potlog(a,b, M):
    res = 1
    while b > 0:
        if b % 2:
            res = (res*a) % M
        a = (a*a) % M
        b /= 2
    return res

def prime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    D = n-1
    S = 0
    while D % 2 == 0:
        D /= 2
        S += 1
    # n-1 = 2^S * D
    STEPS = 16
    for pasos in range(STEPS):
        A = random.randint(1, n-1)
        M = potlog(A,D,n)
        if M == 1 or M == n-1:
            continue
        for k in range(S-1):
            M = (M*M) % n
            if M == n-1:
                break
        else:
            return False
    return True


# pollard's rho

def mcd(a, b):
    return b if a==0 else mcd(b%a,a)

MAX_ITERATIONS = 100000

def factor(n):
    A = random.randint(1,n-1)
    B = random.randint(1,n-1)
    def f(x):
        return (x*(x + B) + A) % n
    x = 2
    y = 2
    d = 1
    iterations = 0
    while d == 1 or d == -1:
        x = f(x)
        y = f(f(y))
        d = mcd(x-y,n)
        iterations += 1
        if iterations > MAX_ITERATIONS:
            return n
    return abs(d)

bases = range(2,11)

def inBase(s, base):
    x = 0
    for digit in s:
        x = x * base + digit
    return x

def isJamcoin(s):
    for b in bases:
        if prime(inBase(s,b)):
            return False
    return True

def jamcoinToString(s):
    return "".join(chr(ord('0') + digit) for digit in s)

if __name__ == "__main__":
    N = 32
    J = 500
    s = dict()
    jamcoin = [1 for i in range(N)]
    while len(s) < J:
        for i in range(1, N-1):
            jamcoin[i] = random.randint(0,1)
        if isJamcoin(jamcoin):
            factorList = [0 for i in bases]
            for i, b in enumerate(bases):
                x = inBase(jamcoin, b)
                factorList[i] = factor(x)
                if factorList[i] == x:
                    break
            else:
                s[jamcoinToString(jamcoin)] = factorList
                print >> sys.stderr, "FOUND", len(s)
    print "Case #1:"
    for jc, factorList in s.iteritems():
        sys.stdout.write(jc)
        for f in factorList:
            sys.stdout.write(" ")
            sys.stdout.write(str(f))
        sys.stdout.write("\n")
