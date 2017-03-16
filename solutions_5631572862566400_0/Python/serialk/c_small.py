from collections import Counter, defaultdict
import itertools

input = raw_input

def parties(seq):
    p = []
    i, imax = 0, 2**len(seq)-1
    while i <= imax:
        s = []
        j, jmax = 0, len(seq)-1
        while j <= jmax:
            if (i>>j)&1 == 1:
                s.append(seq[j])
            j += 1
        p.append(s)
        i += 1
    return p

def ok(L, p):
    for k in itertools.permutations(p):
        for i, e in enumerate(k):
            if not L[e - 1] in (k[(i - 1) % len(k)], k[(i + 1) % len(k)]):
                break
        else:
            return True
    return False

def soluce(t):
    N, L = t
    for p in sorted(parties(list(range(1, N+1))), key=lambda x: -len(x)):
        if ok(L, p):
            return len(p)

cases = []
T = int(input())
for i in range(T):
    N = int(input())
    L = list(map(int, input().split()))
    cases.append((N, L))

from multiprocessing import Pool
pool = Pool(6)
cases = pool.map(soluce, cases)
for i, c in enumerate(cases):
    print('Case #{}: {}'.format(i + 1, c))
