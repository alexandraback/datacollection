"""
https://code.google.com/codejam/contest/6254486/dashboard#s=p2
"""

import fileinput
import signal
import os
import itertools
import sys
import random


def fermat(x, base=2):
    return pow(base, x - 1, x) == 1


def prove_prime(x):
    if x % 2 == 0 or x % 3 == 0:
        return False
    upper = int(x**0.5) + 1
    for i in range(5, upper, 6):
        if x % i == 0 or x % (i + 2) == 0:
            return False
    return True


# Generate them coinz
def generate_coinz(start=0, length=16):
    if start == 0:
        start = '1' + '0' * (length - 2) + '1'
    x = start

    # Register a signal handler so we can stop it whenever we want
    def handler(signum, frame):
        print('Last tried value: ', x)
        sys.exit(1)

    signal.signal(signal.SIGINT, handler)

    while True:
        for base in range(2, 11):
            v = int(x, base)
            if fermat(v, 2) and fermat(v, 3):
                if prove_prime(v):
                    break
        else:
            yield x
        #x = bin(int(x, 2) + 1)[2:]
        x = bin(random.randint(2**(length-1), 2**length-1))[2:-1] + '1'


def show_proof(prime):
    for base in range(2, 11):
        v = int(prime, base)
        for i in range(2, int(v**0.5) + 1, 1):
            if v % i == 0:
                yield i
                break
        else:
            raise Exception('Shit\'s broke yo')


"""
for coin in generate_coinz(length=32):
    print(coin + ' ' + ' '.join(str(x) for x in show_proof(coin)))
    sys.stdout.flush()
"""

lines = fileinput.input()

cases = int(next(lines))

for case in range(1, cases + 1):
    print("Case #{case}:".format(**locals()))
    n, coins = map(int, next(lines).strip().split(' '))
    seen = set()
    for coin in generate_coinz(length=n):
        if coin in seen:
            continue
        seen.add(coin)
        print(coin + ' ' + ' '.join(str(x) for x in show_proof(coin)))
        sys.stdout.flush()
        coins -= 1
        if coins <= 0:
            break


