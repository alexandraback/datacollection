t = int(input())

PRECOMPUTE = 1 << 10

def mkprimes(lim):
    sieve = [True for _ in range(lim)]
    sieve[0] = sieve[1] = False

    for k, v in enumerate(sieve):
        if v:
            yield k
            for i in range(k*k, lim, k):
                sieve[i] = False

primes = list(mkprimes(PRECOMPUTE))

# Tests a smaller range of numbers. This function returning truthy is sufficient for a number to not be prime, but not necessary.
def suffnotprime(v):
    for i in primes:
        if v <= i:
            return 0
        if v % i == 0:
            return i
    return 0

def bitgen(l):
    for v in range((1 << (l - 2)) - 1):
        yield "1%s1" % bin(v)[2:].zfill(l - 2)

def notprimeproof(s):
    for r in range(2,11):
        v = int(s, r)
        if not notprime(v):
            continue

for c in range(t):
    print("Case #%d:" % (c + 1))
    n, j = map(int, input().split())
    for s in bitgen(n):
        if not j:
            break
        proof = []
        for r in range(2,11):
            v = int(s, r)
            p = suffnotprime(v)
            if not p:
                break
            proof.append(str(p))
        else:
            print("%s %s" % (s, " ".join(proof)))
            j -= 1
    if j:
        import sys
        print("Warning, %d cases remain! Consider increasing the size of the precomputed sieve!", file=sys.stderr)
