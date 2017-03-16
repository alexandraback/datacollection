MAXPRIME = 10000
N = 32
J = 500

primes = []
sieve = [True]*MAXPRIME

for i in xrange(2, int(MAXPRIME ** 0.5) + 1):
    if not sieve[i]: continue
    primes.append(i)
    for j in xrange(2*i, MAXPRIME, i):
        sieve[j] = False

bases = {}

for base in xrange(2, 11):
    bases[base] = []
    # look at first p items in list for b*n + 1, for each prime p
    # if find an element at pos i divisible by p, then i is the remainder mod p
    # could use euclid's algo?
    for p in primes:
        if base % p == 0: continue # these won't have one
        for i in xrange(p):
            num = base * i + 1
            if num % p == 0:
                bases[base].append((p, i))

print "Case #1:"
found = 0
for coin in xrange(1, 2**(N-1), 2):
    works = True
    factors = []
    for base in xrange(2, 11):
        coincopy = coin
        cur = 0
        for p in xrange(N-1):
            cur *= base
            if coincopy % 2:
                cur += 1
            coincopy /= 2
        # print "".join(reversed(bin(coin)[2:].zfill(15))) + "1", base, cur
        divs = bases[base]
        has = False
        for div, mod in divs:
            if cur % div == mod:
                has = True
                factors.append(div)
                break
        if not has:
            works = False
            break
    if not works:
        continue
    found += 1
    print "".join(reversed(bin(coin)[2:].zfill(N-1))) + "1", " ".join(map(str, factors))
    if found == J:
        break
