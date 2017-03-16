import string
import itertools

def readint():
    return int(input())


def readfloat():
    return float(input())


def readarray(N, foo=input):
    return [foo() for i in range(N)]


def readlinearray(foo=int):
    return list(map(foo, input().split()))


def GCD(a, b):
    while b:
        a, b = b, a % b
    return a


def gen_primes(max):
    primes = [1]*(max+1)
    for i in range(2, max+1):
        if primes[i]:
            for j in range(i+i, max+1, i):
                primes[j] = 0
    primes[0] = 0
    return [x for x in range(2, max+1) if primes[x]]

primes = gen_primes(2**20)


def get_min_divisor(N):
    for p in primes:
        if N % p == 0:
            return p
        if p * p > N:
            return N
    return N


def get(s):
    for l in string.ascii_uppercase[::-1]:
        if l in s:
            return l * s.count(l) + get(s[:s.index(l)]) + ''.join(x for x in s[s.index(l):] if x != l)
    return ''


case_number = readint()
for case in range(case_number):
    N = readint()
    F = readlinearray()
    F = [x - 1 for x in F]
    best = 0
    for i in range(N, 0, -1):
        for s in itertools.permutations(range(N), i):
            for k in range(i):
                if F[s[k]] not in [s[k - 1], s[(k + 1) % i]]:
                    break
            else:
                print("Case #%d: %s" % (case + 1, i))
                break
        else:
            continue
        break

    #print(F)

    #def destiny(x):
        #chain = []
        #c = set()
        #while x not in c:
            #chain.append(x)
            #c.add(x)
            #x = F[x]
        #if chain[-1] == x:
            #return ('chain', chain)
        #if chain[0] == x:
            #return ('cycle', chain)
        #print(x, chain)
        #return None

    #for i in range(N):
        #print(i, destiny(i))
    #print()
