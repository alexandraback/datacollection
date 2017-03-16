import math
import collections
import itertools
def readint():
    return int(input())
def readfloat():
    return float(input())
def readarray(N, foo=input):
    return [foo() for i in range(N)]
def readlinearray(foo=int):
    return map(foo, input().split())

def gcd(a, b):
    while b:
        a,b = b, a%b
    return a

def gen_primes(max):
    primes = [1]*(max+1)
    for i in range(2, max+1):
        if primes[i]:
            for j in range(i+i, max+1, i):
                primes[j] = 0
    primes[0] = 0
    return [x for x in range(max+1) if primes[x]]

def is_prime(N):
    i = 3
    if not(N % 2):
        return 0
    while i*i < N:
        if not(N % i):
            return 0
        i += 3
    return 1

def is_pow2(x):
    return x == 1 or (x % 2 == 0 and is_pow2(x // 2))


#def check_set(s, V):
    #possible = {0}
    #for c in s:
        #np = set(possible)
        #for p in possible:
            #np.add(p + c)
        #possible = np
    #return set(range(V + 1)).issubset(possible)


#def gen_sets(s, V, r, start=1):
    #rr = []
    #for ss in itertools.combinations(range(1, V + 1), r):
        #if not s.intersection(ss):
            #rr.append(s.union(ss))
    #return rr
    #if r == 0 or start > V:
        #return [s]
    #if start in s:
        #return gen_sets(s, V, r, start + 1)
    #return gen_sets(s, V, r, start + 1) + gen_sets(s.union([start]), V, r - 1, start + 1)

case_number = readint()
for case in range(case_number):
    C, D, V = readlinearray()
    ds = list(readlinearray())
    full_first = 0
    add = 0
    while sum(ds[:full_first]) * C < V:
        if full_first >= len(ds) or sum(ds[:full_first]) * C + 1 < ds[full_first]:
            add += 1
            ds.insert(full_first, sum(ds[:full_first]) * C + 1)
        full_first += 1
    print("Case #%s: %d" % (case + 1, add))
    #add = 0
    #while True:
        #for s in gen_sets(ds, V, add):
            #if check_set(s, V):
                #break
        #else:
            #add += 1
            #continue
        #break
