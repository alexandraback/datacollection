import numpy as np

def solve(B, M):
    Adj = np.zeros((B, B), dtype=int)
    L = B*(B-1)/2
    for pat in range(2**L):
        for i in range(B):
            for j in range(i+1, B):
                Adj[i, j] = pat & 1
                pat >>= 1

        # Compute number of paths
        c = 0
        A = Adj.copy()
        while (A > 0).any():
            c += A[0, B-1]
            A = A.dot(Adj)
        if c == M:
            return 'POSSIBLE', Adj
    return 'IMPOSSIBLE', None

for c in range(input()):
    B, M = map(int, raw_input().split())
    ans, Adj = solve(B, M)
    print 'Case #{}: {}'.format(c+1, ans)
    if ans == 'POSSIBLE':
        for i in range(len(Adj)):
            print ''.join(map(str, Adj[i,:]))
