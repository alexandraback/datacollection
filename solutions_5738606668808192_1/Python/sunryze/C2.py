'''
Created on 09.04.2016

@author: dw

Uses isprime from
http://stackoverflow.com/questions/1801391/what-is-the-best-algorithm-for-checking-if-a-number-is-prime

'''
import sys
import random

def bitstream(n):
    L = 2**n - 1
    while True:
        yield '{:b}'.format(random.randint(0, L)).rjust(n, '0')


def pfac(n, limit=1000):
    """Tries to factorize n, gives up after limit attempts and returns None."""
    if n % 3 == 0:
        return 3

    i = 5
    w = 2

    while i * i <= n and limit > 0:
        if n % i == 0:
            return i

        i += w
        w = 6 - w
        limit -= 1

    return None

def factorize(ds):
    result = [0] * len(ds)
    for i, d in enumerate(ds):
        f = pfac(d)
        if f is None:
            return None
        result[i] = f
    return result


def process_case(N, J):
    result = set()
    for m in bitstream(N-2):
        b = '1' + m + '1'
        ds = [int(b, base) for base in range(2, 11)]
        factors = factorize(ds)
        if factors:
            result.add(tuple([b] + factors))
            if len(result) == J:
                break

    return sorted(result)

if __name__ == '__main__':
    N = int(sys.argv[1])
    J = int(sys.argv[2])
    print("Case #1:")
    for s in process_case(N, J):
        print(' '.join(str(n) for n in s))
