from itertools import combinations
from collections import defaultdict


def increasing(lst):
    return all(a < b for a, b in zip(lst, lst[1:]))


def search():
    for comb in combinations(lines, N):
        trans = tuple(zip(*comb))
        if any(not increasing(l) for l in trans):
            continue
        rem = [l for l in lines if l not in trans and l not in comb]
        if any(rem):
            continue
        cand = defaultdict(int)
        for c in (trans+comb):
            cand[c] += 1
        for c in lines:
            cand[c] -= 1
        for c, i in cand.items():
            if i == 1:
                return c


for case in range(int(input())):
    N = int(input())
    lines = [tuple(map(int, input().split())) for _ in range(2*N-1)]
    lines.sort()
    print('Case #%d:' % (case+1), ' '.join(map(str, search())))
