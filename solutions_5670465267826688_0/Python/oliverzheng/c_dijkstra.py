#!/usr/bin/python

import sys, itertools, pdb

table = {
    '1': {
        '1': (False, '1'),
        'i': (False, 'i'),
        'j': (False, 'j'),
        'k': (False, 'k'),
    },
    'i': {
        '1': (False, 'i'),
        'i': (True, '1'),
        'j': (False, 'k'),
        'k': (True, 'j'),
    },
    'j': {
        '1': (False, 'j'),
        'i': (True, 'k'),
        'j': (True, '1'),
        'k': (False, 'i'),
    },
    'k': {
        '1': (False, 'k'),
        'i': (False, 'j'),
        'j': (True, 'i'),
        'k': (True, '1'),
    },
}

def multiply(a, b):
    (sign, result) = table[a[1]][b[1]]
    if a[0]:
        sign = not sign
    if b[0]:
        sign = not sign
    return (sign, result)

one = (False, '1')
I = (False, 'i')
J = (False, 'j')
K = (False, 'k')

ijk_product = multiply(multiply(I, J), K)

if __name__ == '__main__':
    cases = None
    is_counts = True
    for i, line in enumerate(sys.stdin):
        line = line.strip()

        if cases is None:
            cases = int(line)
            continue

        if is_counts:
            (_, X) = line.split()
            X = int(X)
            is_counts = False
            continue
        else:
            is_counts = True

        can = False

        l = list((False, c) for c in line)
        l_product = reduce(lambda a, b: multiply(a, b), l)
        if (X % 2 == 0 and X % 4 != 0) or l_product == ijk_product:
            has_i = has_j = has_k = False
            doing_i = doing_j = doing_k = False

            current = one
            doing_i = True
            for c in itertools.chain.from_iterable(itertools.repeat(l, min(10, X))):
                current = multiply(current, c)
                #print 'after', current
                if doing_i and current == I:
                    #print 'found i'
                    has_i = True
                    doing_i = False
                    doing_j = True
                    current = one
                elif doing_j and current == J:
                    #print 'found j'
                    has_j = True
                    doing_j = False
                    doing_k = True
                    current = one
                elif doing_k and current == K:
                    #print 'found k'
                    has_k = True
                    doing_k = False
                    current = one
                    break
            can = has_i and has_j and has_k

        print 'Case #%d: %s' % (i / 2, 'YES' if can else 'NO')
