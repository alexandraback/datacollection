#!/usr/bin/env python3

# import numpy
#
# def primesfrom2to(n):
#     """ Input n>=6, Returns a array of primes, 2 <= p < n """
#     sieve = numpy.ones(n/3 + (n%6==2), dtype=numpy.bool)
#     for i in range(1,int(n**0.5)//3+1):
#         if sieve[i]:
#             k=3*i+1|1
#             sieve[       k*k//3     ::2*k] = False
#             sieve[k*(k-2*(i&1)+4)//3::2*k] = False
#     return numpy.r_[2,3,((3*numpy.nonzero(sieve)[0][1:]+1)|1)]

def rwh_primes1(n):
    # http://stackoverflow.com/questions/2068372/fastest-way-to-list-all-primes-below-n-in-python/3035188#3035188
    """ Returns  a list of primes < n """
    sieve = [True] * (n//2)
    for i in range(3, int(n**0.5)+1, 2):
        if sieve[i//2]:
            sieve[i*i//2::i] = [False] * ((n-i*i-1)//(2*i)+1)
    return [2] + [2*i+1 for i in range(1, n//2) if sieve[i]]

primes = list(rwh_primes1(2000))
#print(primes)

def inters(n):
    return [int(n, base) for base in range(2, 11)]

def solve(n, j):
    #mn = int("1" + ("0" * (n-2)) + "1")
    #mx = int("1" * n)
    fmt = '{:0'+str(n-2)+'b}'
    c = 0
    res = []
    while j > 0:
        s = "1" + fmt.format(c) + "1"
        if len(s) > n:
            break
        bases = inters(s)
        #print(s, bases)
        proofs = []
        for b in bases:
            for d in primes:
                if not b % d:
                    proofs.append(d)
                    break
            else:
                break
        if len(proofs) == len(bases):
            res.append("%s %s" % (bases[-1], ' '.join(str(p) for p in proofs)))
            #print(bases[-1], proofs)
            j -= 1
        c += 1

    return "\n".join(res)


testcases = int(input())

for case_n in range(1, testcases+1):
    case_data = map(int, input().split())
    #case_data = input().split()
    print("Case #%i:\n%s" % (case_n, solve(*case_data)))
