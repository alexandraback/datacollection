from random import randint, choice, sample, shuffle
from collections import defaultdict

def solve(tc,J,P,S,K):
    if K >= S:
        print('Case #{}: {}'.format(tc+1,J*P*S))
        for j in range(J):
            for p in range(P):
                for s in range(S):
                    print('{} {} {}'.format(j+1,p+1,s+1))
        return

    print('Case #{}: {}'.format(tc+1,J*P*K))
    chosen = {}
    PS = defaultdict(int)
    JS = defaultdict(int)
    for j in range(J):
        for p in range(P):
            mam = 0
            for s in range(S):
                if mam == K: continue
                if PS[(p,s)] == K: continue
                if JS[(j,s)] == K: continue
                print(j,p,s)
                mam += 1
            assert mam == K

T = int( input() )
for tc in range(T):
    J, P, S, K = [ int(x) for x in input().split() ]
    solve(tc, J, P, S, K)

