from sympy.ntheory import factorint, isprime
import random
import sys

def baseN(num, b, numerals="0123456789abcdefghijklmnopqrstuvwxyz"):
    return ((num == 0) and numerals[0]) or (baseN(num // b, b, numerals).lstrip(numerals[0]) + numerals[num % b])

def get_divisor(n):
    if isprime(n):
        return None
    factors = factorint(n, limit=10000)
    if factors.keys() == [n]:
        return None
    return factors.keys()[0]

def random_number(N):
    inside = baseN(random.getrandbits(N - 2), 2)
    if len(inside) < N - 2:
        inside = '0' * (N - 2 - len(inside)) + inside
    s = '1{0}1'.format(inside)
    ns = [long(s, base=i) for i in xrange(2, 11)]
    return s, ns

def main(N, J):
    done = set()
    print 'Case #1:'
    while len(done) < J:
        s, ns = random_number(N)
        if s in done:
            continue
        ds = []
        for x in ns:
            d = get_divisor(x)
            if d == None:
                break
            ds.append(d)

        if len(ds) != len(ns):
            continue

        done.add(s)
        print s,
        print ' '.join((str(d) for d in ds))

if __name__ == '__main__':
    assert len(sys.argv) == 3, 'Usage: {0} N J'
    main(int(sys.argv[1]), int(sys.argv[2]))
