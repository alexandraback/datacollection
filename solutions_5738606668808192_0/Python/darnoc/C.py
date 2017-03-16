import random
import sympy

N = 16
J = 50

print 'Case #1:'

out = set()
while len(out) < J:
    n = '1' + ''.join(random.choice('01') for _ in xrange(N-2)) + '1'
    nn = [int(n, b) for b in range(2, 11)]
    if not any(sympy.isprime(x) for x in nn):
        out.add((n, tuple(next(iter(sympy.factorint(x))) for x in nn)))
for n,f in out:
    print n, ' '.join(map(str, f))
