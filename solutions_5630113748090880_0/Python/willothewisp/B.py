from collections import Counter

def go(N, papers):
    ct = Counter(x for a in papers for x in a)
    vals = []
    for k, v in ct.items():
        if v % 2 != 0:
           vals.append(k)
    vals.sort()
    return vals

T = int(input())
for tc in range(T):
    N = int(input())
    papers = [[int(s) for s in input().split()] for _ in range(2*N-1)]
    print("Case #{}: {}".format(tc+1, ' '.join(map(str, go(N, papers)))))