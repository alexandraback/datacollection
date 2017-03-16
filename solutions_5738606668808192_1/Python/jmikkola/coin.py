def isPrime(n):
    if n in (2,3,5,7):
        return True
    if n < 10 or n & 1 == 0:
        return False
    div = 3
    while (div*div) < (n*2):
        if n % div == 0:
            return False
        div += 2
    return True
somePrimes = [i for i in xrange(100 * 1000) if isPrime(i)]

def findFact(b):
    for p in somePrimes:
        if (p*p) > (b*2):
            break
        if b % p == 0:
            return p
    return None

def inBase(powers, base):
    tot = 0
    for p in powers:
        tot += base ** p
    return tot

def getDivisors_old(powers):
    proof = []
    for base in xrange(2, 11):
        val = inBase(powers, base)
        fact = findFact(val)
        if fact is None:
            return None
        proof.append(fact)
    return proof

def getDivisors(rendered):
    proof = []
    for base in xrange(2, 11):
        val = int(rendered, base)
        fact = findFact(val)
        if fact is None:
            return None
        proof.append(fact)
    return proof

def render(powers, j):
    return ''.join('1' if i in powers else '0' for i in xrange(j))

def pickPowers(n, j):
    powers = [0]
    p = 1
    while n:
        if n & 1 == 1:
            powers.append(p)
        p += 1
        n = n >> 1
    powers.append(j-1)
    return powers

def verify(rendered, divs):
    for base in xrange(2, 11):
        b = int(rendered, base)
        if b % divs[base - 2] != 0:
            print(rendered, b, divs[base-2])
            raise Exception(rendered + ' ' + str(divs))

T = raw_input()
N, J = map(int, raw_input().split())
print 'Case #1:'
n_found = 0
for n in xrange(2 ** (N-2)):
    pws = pickPowers(n, N)
    rendered = render(pws, N)
    divs = getDivisors(rendered)
    if divs is not None:
        print(rendered + ' ' + ' '.join(map(str,divs)))
        verify(render(pws, N), divs)
        n_found += 1
        if n_found >= J:
            break
