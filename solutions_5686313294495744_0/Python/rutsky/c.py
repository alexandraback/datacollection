# C
import sys

#sys.stdin = open("small.in", "rt")
#sys.stdout = open("small.out", "wt")
sys.stdin = open("C-small-attempt0.in", "rt")
sys.stdout = open("C-small-attempt0.out", "wt")
#sys.stdin = open("C-large.in", "rt")
#sys.stdout = open("C-large.out", "wt")


def solve(N, themes):
    assert N == len(themes)

    w1_to_idx = {}
    w2_to_idx = {}

    themes_indexed = []
    for w1, w2 in themes:
        if w1 not in w1_to_idx:
            idx = len(w1_to_idx)
            w1_to_idx[w1] = idx
        i1 = w1_to_idx[w1]

        if w2 not in w2_to_idx:
            idx = len(w2_to_idx)
            w2_to_idx[w2] = idx
        i2 = w2_to_idx[w2]

        themes_indexed.append((i1, i2))

    min_size = N * 2

    for subset_idx in range(2 ** N):
        got_w1 = [False] * len(w1_to_idx)
        got_w2 = [False] * len(w2_to_idx)

        size = 0
        for i, get in enumerate(('{:0' + str(N) + 'b}').format(subset_idx)):
            if get == '1':
                size += 1
                got_w1[themes_indexed[i][0]] = True
                got_w2[themes_indexed[i][1]] = True

        if all(got_w1) and all(got_w2) and size < min_size:
            min_size = size

    assert min_size <= N
    return N - min_size

if False:
    assert solve(7, [(0, 0), (0, 2), (1, 1), (2, 1), (3, 1), (4, 1), (5, 1)]) == 0
    assert solve(8, [(0, 0), (0, 2), (1, 1), (2, 1), (3, 1), (4, 1), (5, 1), (3, 2)]) == 2
    assert solve(7, [(0, 0), (0, 2), (1, 1), (2, 1), (4, 1), (5, 1), (3, 2)]) == 1
    for i in range(100):
        assert solve(16, [(0, 0), (0, 2)] + [(x, 1)for x in range(1, 15)]) == 0

else:
    cases = int(input())
    for case_idx in range(cases):
        N = int(input())
        themes = [input().split() for i in range(N)]
        print("Case #{}: {}".format(case_idx + 1, solve(N, themes)))
