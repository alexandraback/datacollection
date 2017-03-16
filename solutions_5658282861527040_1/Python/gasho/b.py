#!/usr/bin/env python

MAX_DIGITS = 30


def g(a, b, k, cache):
    result = 0
    # 0 0
    new_a = a[1:] if a[0] == '0' else '1' * (len(a) - 1)
    new_b = b[1:] if b[0] == '0' else '1' * (len(b) - 1)
    result += f(new_a, new_b, k[1:], cache)
    # 0 1
    if b[0] == '1':
        new_a = a[1:] if a[0] == '0' else '1' * (len(a) - 1)
        result += f(new_a, b[1:], k[1:], cache)
    # 1 0
    if a[0] == '1':
        new_b = b[1:] if b[0] == '0' else '1' * (len(b) - 1)
        result += f(a[1:], new_b, k[1:], cache)
    return result


def h(a, b, k, cache):
    result = 0
    # 1 1
    if a[0] == '1' and b[0] == '1':
        result += f(a[1:], b[1:], k[1:], cache)
    return result


def f(a, b, k, cache):
    if (a, b, k) in cache:
        return cache[(a, b, k)]
    elif not a:
        return 1
    result = 0
    if k[0] == '0':
        result += g(a, b, k, cache)
    else:
        result += g(a, b, '1' * len(k), cache)
        result += h(a, b, k, cache)
    cache[(a, b, k)] = result
    return result


def brute(A, B, K):
    result = 0
    for a in xrange(A):
        for b in xrange(B):
            if a & b < K:
                result += 1
    return result


def solve(A, B, K):
    a = bin(A - 1)[2:].zfill(MAX_DIGITS)
    b = bin(B - 1)[2:].zfill(MAX_DIGITS)
    k = bin(K - 1)[2:].zfill(MAX_DIGITS)
    cache = {}
    return f(a, b, k, cache)


def validate():
    N = 100
    for A in xrange(1, N):
        print A
        for B in xrange(1, N):
            for K in xrange(1, N):
                expected = brute(A, B, K)
                returned = solve(A, B, K)
                assert expected == returned, (A, B, K, expected, returned)


def main():
    n_tests = int(raw_input())
    for test in xrange(1, n_tests + 1):
        A, B, K = map(int, raw_input().split())
        print 'Case #%d: %d' % (test, solve(A, B, K))


if __name__ == '__main__':
    main()
