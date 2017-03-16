import itertools

def fall(K, C, next_source_idx):
    i = next_source_idx
    next_source_idx += 1
    for l in range(C - 1):
        if next_source_idx < K:
            i = i * K + next_source_idx
            next_source_idx += 1
        else:
            i = i * K

    return i, next_source_idx


def indexes(K, C):
    res = []

    next_source_idx = 0
    while next_source_idx < K:
        i, next_source_idx = fall(K, C, next_source_idx)
        res.append(i)

    return [i + 1 for i in res]


def solve(N):
    if N == 0:
        return "INSOMNIA"

    digits = set()
    for i in itertools.count(1):
        digits = digits.union(str(i * N))

        if len(digits) == 10:
            return i * N

if False:
    assert solve(0) == "INSOMNIA"
    assert solve(1) == 10
    assert solve(2) == 90
    assert solve(11) == 110
    assert solve(1692) == 5076
    solve(10**6 - 1)

else:
    T = int(input())

    for case_idx in range(T):
        N = int(input())

        print("Case #{}: {}".format(case_idx + 1, solve(N)))
