#!/usr/bin/python3

from itertools import compress, islice, count, cycle

from codejam import CodeJam

def primes():
    D = { 9: 3, 25: 5 }
    yield 2
    yield 3
    yield 5
    MASK= 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0,
    MODULOS= frozenset( (1, 7, 11, 13, 17, 19, 23, 29) )
    for q in compress(
            islice(count(7), 0, None, 2),
            cycle(MASK)):
        p = D.pop(q, None)
        if p is None:
            D[q*q] = q
            yield q
        else:
            x = q + 2*p
            while x in D or (x%30) not in MODULOS:
                x += 2*p
            D[x] = p

from math import sqrt
def findfactor(i):
    s = int(sqrt(i))
    for p in primes():
        if p > s:
            return None
        elif i % p == 0:
            return p

def jamcoins(f):
    (length, num) = (int(_) for _ in f.readline().split())
    n = 0
    coins = []
    while len(coins) < num:
        factors = []
        s = '1{n:0{width}b}1'.format(n=n, width=length-2)
        for base in range(2, 11):
            factors.append(findfactor(int(s, base)))
            if factors[-1] is None:
                break
        else:
            coins.append((s, factors))
        n += 1
    out = ''
    for coin in coins:
        out += '\n' + coin[0] + ' '
        out += ' '.join(str(_) for _ in coin[1])
    return out


cj = CodeJam(jamcoins)

# After importing cj into an interactive Python shell, I test the code by
# running:
# >>> cj.processtext("""examples""")
#
# Then after downloading the problem set, I solve it with:
# >>> cj.processfile('filename')
