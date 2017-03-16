# Solution to "Coin Jam" for Google Code Jam 2016
# by Peter Mattsson (quantum.caffeine@gmail.com)
import sys

def cases(inputFile):
    with open(inputFile, 'r') as f:
        numCases = int(f.readline())
        for _ in range(numCases):
            yield [int(x) for x in f.readline().split()]

def getPrimes(limit):
    primes = []
    for n in xrange(2, limit+1):
        if not any(n%p == 0 for p in primes):
            primes.append(n)
    return primes

primes = getPrimes(1000)

def check(n, primes):
    for p in primes:
        if n%p == 0:
            return p
    return 0

def toBase(m, n, base, powers):
    return sum(powers[base][a]*int(x) for a, x in enumerate(bin(m)[2:].zfill(n)))

def test(m, n, powers):
    results = [check(toBase(m, n, base, powers), primes) for base in range(2, 11)]
    return results

def solve(n, j):
    results = []
    powers = [[], []]
    for x in range(2, 11):
        powers.append([x**p for p in range(n-1, -1, -1)])
    x = 2**(n-1) - 1
    found = 0
    while found < j:
        x += 2
        t = test(x, n, powers)
        if all(a != 0 for a in t):
            results.append((bin(x)[2:], t))
            found += 1
    return results

with open(sys.argv[2], 'w') as f:
    for num, args in enumerate(cases(sys.argv[1])):
        f.write("Case #%d:\n"%(num+1,))
        results = solve(*args)
        for jamcoin, evidence in results:
            f.write("%s %s\n"%(jamcoin, ' '.join(str(x) for x in evidence)))
