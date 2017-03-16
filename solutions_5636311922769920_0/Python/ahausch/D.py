import sys
import math

def solve(K, C, S):
    if (S < math.ceil(K / C)):
        return "IMPOSSIBLE"
    S = math.ceil(K / C)

    i = 0
    r = []
    
    for s in range(S):
        pos = 0
        for c in range(C):
            if (i >= K):
                break
            pos = pos * K + i
            i += 1
        r.append(str(pos + 1))
    
    return r

fin = sys.stdin

T = int(fin.readline())

for t in range(T):
    (K, C, S) = map(int, fin.readline().split())
    print("Case #{0}: {1}".format(t + 1, ' '.join(solve(K, C, S))))

fin.close()
