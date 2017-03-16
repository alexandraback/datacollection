import pyprimes
import random
import sympy
import sys

raw_input() # = 1
N, J = map(int, raw_input().split())

print 'Case #1:'
seen = set()
while J > 0:
    s = '1'
    for i in range(N-2):
        s += str(random.randint(0, 1))
    s += '1'
    if s in seen:
        continue
    seen.add(s)

    ok = True
    for base in range(2, 11):
        x = int(s, base)
        if sympy.ntheory.primetest.isprime(x):
            ok = False
            break

    if not ok:
        continue

    sys.stdout.flush()
    factors = []
    for base in range(2, 11):
        x = int(s, base)
        for p in pyprimes.primes():
            if x % p == 0:
                factors.append(p)
                break
            if p > 1234567:
                ok = False
                break
        if not ok:
            break
    if not ok:
        continue
    print s, ' '.join(map(str, factors))
    J -= 1
    sys.stdout.flush()
