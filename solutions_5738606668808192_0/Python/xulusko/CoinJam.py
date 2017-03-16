from random import randint
from pyprimes import nprimes

N = 16
J = 50

jamcoins = set()
somePrimes = list(nprimes(47))[1:]

def findDiv(val):
    for p in somePrimes:
        if val % p == 0: return p
    return None

def getDivisors(coin):
    divs = []
    for base in range(2, 11):
        val = int(coin, base)
        div = findDiv(val)
        if not div: return None
        divs.append(div)
    return tuple(divs)

while len(jamcoins) < J:
    coin = ''
    for i in range(N-2): coin += str(randint(0, 1))
    coin = '1' + coin + '1'
    divs = getDivisors(coin)
    if divs: jamcoins.add((coin, divs))

print('Case #1:')
for coin, divs in jamcoins: print(coin, ' '.join(map(str, divs)))
