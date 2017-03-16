from copy import copy
from multiprocessing.pool import Pool
from random import shuffle
from itertools import count, product
from random import randint
from sys import stdout
from time import time

namein = 'C-large.in'
nameout = 'large.out'

def solve(J, P, S, K):
    m1 = {}
    rm1 = {}
    m2 = {}
    m3 = {}
    m4 = {}
    for i, p in enumerate(product(range(J), range(P), range(S))):
        m1[p] = i
        rm1[i] = p
    for i, p in enumerate(product(range(J), range(P))):
        m2[p] = i
    for i, p in enumerate(product(range(J), range(S))):
        m3[p] = i
    for i, p in enumerate(product(range(P), range(S))):
        m4[p] = i
    a = [0 for _ in range(J*P*S)]
    for p, i in m1.items():
        a[i] = (m2[p[0], p[1]], m3[p[0], p[2]], m4[p[1], p[2]])

    start = time()
    ans = []
    while time()-start <= 1:
        used = [[0 for _ in m2], [0 for _ in m3], [0 for _ in m4]]
        shuffle(a)
        now = []
        for i in range(len(a)):
            if len(now)+len(a)-i <= len(ans):
                break
            for j in range(3):
                if used[j][a[i][j]] >= K:
                    break
            else:
                for j in range(3):
                    used[j][a[i][j]] += 1
                now.append(i)
        if len(now) > len(ans):
            ans = copy(now)
    ret = [str(len(ans))]
    for i in ans:
        ret.append(' '.join(str(aii+1) for aii in rm1[i]))
    return '\n'.join(ret)

if __name__ == '__main__':
    fin = open(namein, 'r')
    fout = open(nameout, 'w')
    # fout = stdout
    T = int(fin.readline())
    res = []
    with Pool(6) as pool:
        for i in range(1, T+1):
            J, P, S, K = [int(s) for s in fin.readline().split()]
            res.append(pool.apply_async(solve, (J, P, S, K)))
        for i, r in enumerate(res):
            print(i)
            print('Case #{}: {}'.format(i+1, r.get()), file=fout)
