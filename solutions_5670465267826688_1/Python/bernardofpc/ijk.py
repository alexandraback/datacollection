def baseprod(a,b):
    if a == 1: return b
    if b == 1: return a
    if a == 2: #i
        if b == 2: return -1
        if b == 3: return 4
        if b == 4: return -3
    if a == 3: #j
        if b == 2: return -4
        if b == 3: return -1
        if b == 4: return 2
    if a == 4: #k
        if b == 2: return 3
        if b == 3: return -2
        if b == 4: return -1

def ijk_prod(a,b):
    if a > 0 and b > 0:
        return baseprod(a,b)
    if a > 0 and b < 0:
        return -baseprod(a,-b)
    if a < 0 and b > 0:
        return -baseprod(-a,b)

    return baseprod(-a,-b)

def ijk_pow(a,n):
    if a == 1:
        return 1
    if a == -1:
        if n % 2 == 0: return 1
        else:          return -1

    if n % 4 == 0: return 1
    if n % 2 == 0: return -1

    if n % 4 == 1: return a
    else:          return -a


def ijk_to_num(a):
    if a == 'i': return 2
    if a == 'j': return 3
    if a == 'k': return 4

def find_ij(v, rep):
    cand = v*rep
    p = 1
    target = 2
    for a in cand:
        p = ijk_prod(p,a)
        if p == target:
            if target == 3:
                return 1
            p = 1
            target = 3
            continue

    return 0


def solve(s, L, X):
    ijk_s = [ijk_to_num(x) for x in s]
    prodzao = 1
    for a in ijk_s:
        prodzao = ijk_prod(prodzao,a)

    totProd = ijk_pow(prodzao, X)
    if totProd != -1:
        return 0

    if X > 8: X = 8
    return find_ij(ijk_s, X)


import sys

T = int(sys.stdin.readline())

for icase in range(1,T+1):
    li = sys.stdin.readline()
    [L, X] = [int(x) for x in li.split()]
    s = sys.stdin.readline().strip()

    print('Case #{}: '.format(icase), end='')

    if solve(s,L,X) == 0: print('NO')
    else: print('YES')
