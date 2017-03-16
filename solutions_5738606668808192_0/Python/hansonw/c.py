import pyprimes
import random

raw_input() # = 1
N, J = map(int, raw_input().split())

print 'Case #1:'
while J > 0:
    s = '1'
    for i in range(N-2):
        s += str(random.randint(0, 1))
    s += '1'

    ok = True
    for base in range(2, 11):
        x = int(s, base)
        if pyprimes.isprime(x):
            ok = False
            break

    if not ok:
        continue

    print s,
    factors = []
    for base in range(2, 11):
        x = int(s, base)
        f = pyprimes.factorise(x)
        p, _ = f.next()
        factors.append(p)
    print ' '.join(map(str, factors))
    J -= 1
