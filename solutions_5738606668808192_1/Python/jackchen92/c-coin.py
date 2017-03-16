PRIMES = []
for x in xrange(2, 300):
    for p in PRIMES:
        if x % p == 0:
            break
    else:
        PRIMES.append(x)

def divisor(x):
    for p in PRIMES:
        if x % p == 0:
            return p
    return None

print 'Case #1:'
T = int(raw_input())
n, J = [int(tok) for tok in raw_input().split()]
for m in xrange(2 ** (n-2+1)):
    vals = [b**(n-1) + 1 for b in range(11)]
    for j in xrange(n-2):
        if (m >> j) & 1:
            for b in xrange(2, 11):
                vals[b] += b ** (j+1)
    #print m, vals[10]
    divs = []
    for v in vals[2:]:
        d = divisor(v)
        if d:
            divs.append(d)
        else:
            break
    else:
        print vals[10], ' '.join([str(d) for d in divs])
        J -= 1
        if J == 0:
            break
