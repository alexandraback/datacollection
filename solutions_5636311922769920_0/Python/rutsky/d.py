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


def solve(K, C, S):
    s = indexes(K, C)

    if len(s) > S:
        return "IMPOSSIBLE"
    else:
        return " ".join(map(str, s))

if False:
    assert indexes(1, 1) == [1]
    assert indexes(1, 2) == [1]
    assert indexes(3, 1) == [1, 2, 3]
    assert indexes(3, 2) == [2, 7]
    assert indexes(3, 3) == [6]
    assert indexes(3, 4) == [16]
    assert indexes(4, 1) == [1, 2, 3, 4]
    assert indexes(4, 2) == [2, 12]
    assert indexes(4, 3) == [7, 49]

else:
    T = int(input())

    for case_idx in range(T):
        K, C, S = map(int, input().split())

        print("Case #{}: {}".format(case_idx + 1, solve(K, C, S)))