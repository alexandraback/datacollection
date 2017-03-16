import random
import sympy
import sys

N = 32
J = 500

print 'Case #1:'

out = set()
while len(out) < J:
    n = '1' + ''.join(random.choice('01') for _ in xrange(N-2)) + '1'
    nn = [int(n, b) for b in range(2, 11)]
    f = []
    for x in nn:
        ff = sympy.factorint(x, limit=100)
        if len(ff) == 1: break
        f += [next(iter(ff))]
    else:
        out.add((n, tuple(f)))
        sys.stderr.write(`len(out)`+'\n')

for n,f in out:
    print n, ' '.join(map(str, f))
