# coding: utf-8

import sys

class itertools:
    @staticmethod
    def rep_with_index(chars, nrep):
        for i in xrange(nrep):
            for index, char in enumerate(chars):
                yield index, char

idx = {"1": 0, "i": 1, "j": 2, "k": 3}
tab = [
    [( 1, "1"), ( 1, "i"), ( 1, "j"), ( 1, "k")],
    [( 1, "i"), (-1, "1"), ( 1, "k"), (-1, "j")],
    [( 1, "j"), (-1, "k"), (-1, "1"), ( 1, "i")],
    [( 1, "k"), ( 1, "j"), (-1, "i"), (-1, "1")],
]

def qmul(q1, q2):
    r = tab[idx[q1[1]]][idx[q2[1]]]
    sign = q1[0] * q2[0] * r[0]
    return (sign, r[1])

def qprod(qs):
    result = (1, "1")
    for q in qs:
        result = qmul(result, q)
    return result

def qpow(q, n):
    return qprod([q for i in range(n % 4)])

def solve(chars, nrep):
    if qpow(qprod(((1, ch) for ch in chars)), nrep) != (-1, "1"):
        return "NO"
    it = iter(itertools.rep_with_index(chars, nrep))
    try:
        def search(it, val):
            index0, char0 = next(it)
            initial = current = (1, char0)
            while True:
                if current == val:
                    return True
                index, char = next(it)
                current = qmul(current, (1, char))
                if index == index0 and char == char0 and current == initial:
                    return False
        if not search(it, (1, "i")):
            return "NO"
        if not search(it, (1, "j")):
            return "NO"
    except StopIteration:
        return "NO"
    return "YES"

def main(fp):
    T = int(fp.readline())
    for t in range(T):
        L, X = tuple(map(int, fp.readline().strip().split(' ')))
        chars = fp.readline().strip()
        result = solve(chars, X)
        print 'Case #{}: {}'.format(t + 1, result)

if __name__ == '__main__':
    if len(sys.argv) == 1:
        main(sys.stdin)
    elif len(sys.argv) == 2:
        with open(sys.argv[1]) as f:
            main(f)
    else:
        print >> sys.stderr, "Usage: python {} INPUT_FILE".format(sys.argv[0])
        sys.exit(1)
