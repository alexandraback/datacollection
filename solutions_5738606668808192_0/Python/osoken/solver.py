# coding: UTF-8

import sys


primes = [2, 3, 5, 7, 11, 13, 19]


def gcd(x, y):
    _x = x
    _y = y
    if _x < _y:
        _x = y
        _y = x
    while _x != 0:
        _z = _y % _x
        _y = _x
        _x = _z
    return _y


def mod_poly(b, q, n):
    res = [1]
    tmp = 1
    for e in range(n-1):
        tmp *= b
        tmp %= q
        res.insert(0, tmp)
    return tuple(res)


def jam(N, J):
    polynomials = {
        b: {
            p: mod_poly(b, p, N) for p in primes if gcd(b, p) == 1
        } for b in range(2, 11)
    }
    j = 0
    i = 0
    while True:
        if j >= J:
            raise StopIteration()
        a = []
        c = '1' + ('{0:0>'+str(N-2)+'b}').format(i) + '1'
        for b, candidate in polynomials.items():
            flg = False
            for p, polynom in candidate.items():
                if sum([coef for coef, digit in zip(polynom, c) if
                        digit == '1']) % p == 0:
                    a.append(p)
                    flg = True
                    break
            if not flg:
                break
        if len(a) == 9:
            j += 1
            yield {'coin': c, 'divisors': a}
        i += 1
    raise StopIteration()

if __name__ == '__main__':
    problemCounts = int(sys.stdin.readline())
    pn, pj = map(int, sys.stdin.readline().strip().split(' '))
    sys.stdout.write('Case #1:\n')
    for ans in jam(pn, pj):
        sys.stdout.write(
            ans['coin'] + ' ' + ' '.join(map(str, ans['divisors'])) + '\n')
