T = int(input())
for tid in range(1,T+1):
    K, C, S = [ int(x) for x in input().split() ]
    min_count = (K+C-1) // C
    if S < min_count:
        print('Case #{}: IMPOSSIBLE'.format(tid))
        continue
    best = [ 0 for _ in range(min_count) ]
    for i in range(min_count):
        for j in range(C):
            curr = (C*i+j) % K
            best[i] = best[i] * K + curr
    print('Case #{}: {}'.format(tid,' '.join(str(x+1) for x in best)))
