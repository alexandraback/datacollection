import sys, random
from math import sqrt

def any_factor(n):
    i = 2
    while i <= 100:
        if n % i == 0:
            return i
        i += 1
    return None

def make_jam_coin(s):
    factors = []
    for base in range(2, 10+1):
        fact = any_factor(int(s, base))
        if fact is not None:
            factors.append(str(fact))
        else:
            return None
    return factors

def generate_jam_coin(n):
    while True:
        randbits = random.getrandbits(n-2)
        candidate = '1{}1'.format(''.join(str(1 & (randbits >> i)) for i in range(n-2)))
        jam_coin = make_jam_coin(candidate)
        if jam_coin:
            return (candidate, jam_coin)

next(sys.stdin)
N, J = (int(s) for s in next(sys.stdin).strip().split(' '))
print('Case #1:')
random.seed(42)
for i in range(J):
    coin, factors = generate_jam_coin(N)
    print(' '.join([coin] + factors))
