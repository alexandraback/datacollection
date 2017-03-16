#! /usr/bin/env python

def main():
    power = 16 # or 32
    num_primes = 50
    counter = 1
    primes = list(erat(power))
    print 'Case #1:'
    for x in range(2**(power-1) + 1, 2**power, 2):
        w = get_factors(x, primes)
        if w:
            print '{} {}'.format(bin(x)[2:], ' '.join(map(str, w)))
            if counter >= num_primes:
                return
            counter += 1

def erat(bound):
    # iterator of primes < sqrt(2**16)
    D = {}
    for q in range(2, 2**(bound/2)+1):
        p = D.get(q, None)
        if p is None:
            yield q
            D[q*q] = q
        else:
            x = p + q
            while x in D:
                x += p
            D[x] = p


def get_factors(x, primes):
    # if bin(x) interpreted in base 2..10 has factors, return as an array, else None.
    s =  bin(x)[2:]
    array = []
    for base in range(2, 11):
        num = int(s, base)
        for p in primes:
            if num % p == 0:
                array.append(p)
                break
        else:
            return None
    return array


if __name__ == '__main__':
    main()
