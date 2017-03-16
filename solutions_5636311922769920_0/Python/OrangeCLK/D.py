import math

T = eval(input())

for caseNum in range(T):
    [K, C, S] = [eval(x) for x in input().split()]
    if S < math.ceil(K / C):
        print('Case #{}: IMPOSSIBLE'.format(caseNum + 1))
        continue
    obp = []
    p = 0
    while p < K:
        cur = p
        p += 1
        for i in range(1, C):
            cur *= K
            if p < K:
                cur += p
                p += 1
        obp.append(cur + 1)

    print('Case #{}: {}'.format(caseNum + 1, ' '.join(str(x) for x in obp)))
