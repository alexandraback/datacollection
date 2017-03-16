from itertools import permutations, groupby

def test(p):
    seen = []
    cur = p[0]
    for c in p:
        if c in seen:
            return False
        if c != cur:
            seen.append(cur)
            cur = c
    return True
        

def solve(N, L):
    L = [''.join(c for c,l in groupby(li)) for li in L]
    for i in range(N):
        for t in L[i][1:-1]:
            for j in range(N):
                if j == i:
                    continue
                if t in L[j]:
                    return 0
    L = [''.join([li[0], li[-1]]) for li in L]
    c = 0
    for p in permutations(L):
        if test(''.join(p)):
            c += 1
    return c

import sys

T = input()
for i in range(T):
    N = input()
    L = raw_input().split()
    print "Case #{}: {}".format(i+1, solve(N, L))
#    sys.stderr.write('{} '.format(i+1))
