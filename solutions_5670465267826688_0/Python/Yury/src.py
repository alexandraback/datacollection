#!/usr/bin/python3

import sys
from itertools import *
from functools import *
from pprint import pprint

class ErrNo(Exception):
    pass

def gen_mapping():
    EM = "1ijk i1kj jk1i kji1".split()
    SM = "0000 0101 0110 0011".split()

    DS = { '1' : 0,
           'i': 1,
           'j': 2,
           'k': 3, }

    DDS = { '0':0, '1':4 }

    EM = [[DS[i] for i in line] for line in EM]

    for i in range(4):
        for j in range(4):
            EM[i][j] = (EM[i][j] + DDS[SM[i][j]]) % 8

    EM = [[ (EM[i%4][j%4] + int(i//4 != j//4)*4) % 8
            for j in range(8)]
            for i in range(8)]

    #pprint(EM, sys.stderr)
    for i in range(4):
        for j in range(4):
            assert EM[i][j] == EM[i+4][j+4], (i, j)
            assert EM[i+4][j] == EM[i][j+4], (i, j)
            assert EM[i][j] == (EM[i][j+4] + 4)%8, (i, j)
    for i in range(8):
        assert EM[i][0] == EM[0][i] == i
    return EM

def tabul(EM, LL):
    LL = list(accumulate(LL, lambda x, y: EM[x][y]))
    #pprint(LL, stream=sys.stderr)
    P = LL[-1]
    LL = [LL] + [P]*3
    LL = list(accumulate(LL,
            lambda prev, P: [EM[P][x] for x in prev]))
    #perr(P, LL)
    return LL


def solve(EM, LL, X):
    LL = tabul(EM, LL)
    if LL[(X+3)%4][-1] != 4:
        return
    ks = { 1:set(), 3:set() }
    for i in range(len(LL)):
        line = LL[i]
        for j in range(len(line)):
            k = j + i*len(line)
            el = line[j]
            if el in ks:
                ks[el].add(k)
    #perr(ks)
    if not (ks[1] and ks[3]):
        return
    LE = len(LL[0])
    if X <= 4:
        mak = X * LE
        k3 = max((k for k in ks[3] if k < mak), default=-1)
        if k3 < 0:
            return
        k1 = min(ks[1])
        if k1 < k3:
            return True
        return
    elif X <= 8:
        if min(ks[1]) < max(ks[3]):
            return True
        assert X > 4
        mak = (X - 4) * LE
        k3 = max((k for k in ks[3] if k < mak), default=-1)
        if k3 >= 0:
            return True
        return
    else:
        return True
    assert False

def parse(EM, ist):
    L, X = [int(k) for k in ist.readline().split()]
    LL = ist.readline().strip()
    try:
        assert L == len(LL), (L, LL)
        M = { 'i': 1, 'j':2, 'k':3 }
        LL = [M[l] for l in LL]
    except:
        err(L, X, LL)
        raise
    return LL, X

def main():
    EM = gen_mapping()
    #pprint(EM, stream=sys.stderr)
    T = int(sys.stdin.readline())
    for i in range(T):
        #err('Case {}'.format(i))
        res = solve(EM, *parse(EM, sys.stdin))
        res = 'YES' if res else 'NO'
        print('Case #{}: {}'.format(i+1, res))

def err(*m):
    print(*m, file=sys.stderr)

def perr(*m):
    pprint(m, stream=sys.stderr)

if __name__ == '__main__':
    sys.exit(main())
