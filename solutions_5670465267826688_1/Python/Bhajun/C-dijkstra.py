#!/usr/bin/env python

import itertools, sys


def multiply(n, m):
    signed = n.startswith('-') != m.startswith('-')
    n, m = n.lstrip('-'), m.lstrip('-')

    if n == '1' or m == '1': return ('-' if signed else '') + (n if m == '1' else m)
    if n == m: return ('-' if not signed else '') +'1'

    if n == 'i' and m == 'j': return ('-' if signed else '') +'k'
    if n == 'i' and m == 'k': return ('-' if not signed else '') +'j'
    if n == 'j' and m == 'i': return ('-' if not signed else '') +'k'
    if n == 'j' and m == 'k': return ('-' if signed else '') +'i'
    if n == 'k' and m == 'i': return ('-' if signed else '') +'j'
    if n == 'k' and m == 'j': return ('-' if not signed else '') +'i'


if __name__ == '__main__':
    T = int(sys.stdin.readline())
    
    for i in range(T):
        L, X = list(map(int, sys.stdin.readline().split()))
        S = sys.stdin.readline().strip()

        # Find prefix and suffix arrays
        prefix = [S[0]]
        suffix = [S[-1]]

        for j in range(1, L):
            prefix.append(multiply(prefix[-1], S[j]))
            suffix.append(multiply(S[-j - 1], suffix[-1]))

        suffix = list(reversed(suffix))

        # Check total product
        if X % 4 == 0:
            print('Case #%d: NO' % (i + 1))
            continue

        product = prefix[-1]

        for _ in range(X % 4 - 1):
            product = multiply(product, prefix[-1])

        if product != '-1':
            print('Case #%d: NO' % (i + 1))
            continue

        # Slow check, iterating over entire array
        i_found, j_found = False, False
        product = '1'

        for c in S * min(X, 8):
            product = multiply(product, c)

            if product == 'i':
                i_found = True
            if i_found and product == 'k':
                j_found = True
                break

        print('Case #%d: %s' % (i + 1, 'YES' if j_found else 'NO'))