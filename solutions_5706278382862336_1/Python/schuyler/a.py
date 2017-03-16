limit = 1000000
primes = [2,3]
for i in xrange(4, limit+1):
    isPrime = True
    for prime in primes:
        if i%prime == 0:
            isPrime = False
            break
        elif prime*prime > i:
            break
    if isPrime:
        primes.append(i)

def factor(x):
    if x in primes or x == 1:
        return [x]
    out = []
    while x not in primes:
        foundOne = False
        for p in primes:
            if x%p == 0:
                out.append(p)
                x /= p
                foundOne = True
                break
        if not foundOne:
            break
    return out + [x]

for T in range(1, input()+1):
    P, Q = [int(x) for x in raw_input().split('/')]
    pfact, qfact = factor(P), factor(Q)

    if max(pfact) > 1: # reduce
        factors = set(pfact) & set(qfact)
        while len(factors) > 0:
            for f in factors:
                pfact.remove(f)
                qfact.remove(f)
            factors = set(pfact) & set(qfact)
        if len(pfact) == 0:
            pfact = [1]
        P = reduce(lambda x,y:x*y, pfact)
        Q = reduce(lambda x,y:x*y, qfact)

    if max(qfact) > 2: # q not power of 2
        res = "impossible"
    else:
        res = 1
        while 2**res <= P:
            res += 1
        res = qfact.count(2) - res + 1


    print "Case #" + str(T) + ": " + str(res)