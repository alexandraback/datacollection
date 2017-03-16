from math import sqrt
from itertools import count, islice, product, chain


def is_prime(n): #check if n (b10) is prime (FUZZY, skips a lot but fine)
    return n > 1 and all(n%i for i in range(2, int(n**0.1)+1)) #it's ok to miss some

def factor(n):
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return i

def generate(n): #generate all jamcoins of length n
    nvar = n - 2
    return ['1' + ''.join(a) + '1' for a in product(['0', '1'], repeat=nvar)]

def generate_pad(n, pad): #generate all jamcoins of length n, with pad # of padded digits on left
    nvar = n - pad - 2
    return ['1' + ('0' * pad) + ''.join(a) + '1' for a in product(['0', '1'], repeat=nvar)]

def all_bases(jamcoin): #return list of values in bases 2-10 for jamcoin
    return [int(jamcoin, i) for i in range(2, 11)]

def is_any_prime(jamcoin): #check if any base values are prime for the jamcoin. false = good
    for n in all_bases(jamcoin):
        if is_prime(n):
            return True
    return False


print ('Case #1:')
n = 32
jamcoins = generate_pad(n, 16)
i_jamcoin = 0
results = []

while len(results) < 500:
    coin = jamcoins[i_jamcoin]
    i_jamcoin += 1
    if is_any_prime(coin):
        next
    else:
        print('{} {}'.format(coin, ' '.join(map(str, map(factor, all_bases(coin))))))
        results.append(coin)
