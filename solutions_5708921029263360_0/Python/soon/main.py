#!/usr/bin/env python3

import random


def generate_all(j, p, s):
    for jj in range(1, j + 1):
        for pp in range(1, p + 1):
            for ss in range(1, s + 1):
                yield jj, pp, ss


def solve_impl(j, p, s, k, all):
    jp = {}
    js = {}
    ps = {}

    for jj, pp, ss in all:
        if jp.get((jj, pp), 0) < k and js.get((jj, ss), 0) < k and ps.get((pp, ss), 0) < k:
            jp[jj, pp] = jp.get((jj, pp), 0) + 1
            js[jj, ss] = js.get((jj, ss), 0) + 1
            ps[pp, ss] = ps.get((pp, ss), 0) + 1
            yield jj, pp, ss


def solve(j, p, s, k):
    best = []
    for i in range(10000):
        all = list(generate_all(j, p, s))
        random.shuffle(all)
        ans = list(solve_impl(j, p, s, k, all))
        if len(ans) > len(best):
            best = ans
    return best


# def run_all_tests():
#     cases = {
#         (1, 1): ['AB'],
#         (2, 2): ['AB', 'AB'],
#         (3, 3): ['AB', 'AB', 'AB'],
#         (4, 4): ['AB', 'AB', 'AB', 'AB'],
#         (6, 1, 2, 3): ['AA', 'A', 'B', 'CC', 'AD', 'AD', 'AD'],
#         (3, 2, 6, 1, 3): ['CC', 'C', 'D', 'BB', 'AA', 'A', 'CE', 'CE', 'CE'],
#         (2, 2): ['AB', 'AB'],
#         (3, 2, 2): ['A', 'AA', 'BC', 'BC'],
#         (1, 1, 2): ['C', 'A', 'BC'],
#         (2, 3, 1): ['B', 'C', 'AB', 'AB'],
#         (3, 2, 3): ['BB', 'AC', 'AC', 'AC'],
#         (4, 2, 3): ['A', 'BB', 'AC', 'AC', 'AC'],
#         (2, 3, 3): ['AA', 'BC', 'BC', 'BC'],
#         (3, 4, 2): ['B', 'CC', 'AB', 'AB', 'AB'],
#         (2, 2, 3): ['C', 'AA', 'BC', 'BC'],
#         (3, 1, 2): ['A', 'B', 'AC', 'AC'],
#         (3, 1, 3): ['B', 'AC', 'AC', 'AC'],
#         (4, 3, 2): ['A', 'CC', 'AB', 'AB', 'AB'],
#         (3, 2, 1): ['A', 'C', 'AB', 'AB'],
#         (2, 3, 2): ['B', 'AA', 'BC', 'BC'],
#         (3, 3, 3): ['AA', 'A', 'BC', 'BC', 'BC'],
#         (1, 2, 1): ['B', 'A', 'BC'],
#         (2, 4, 3): ['B', 'AA', 'BC', 'BC', 'BC'],
#         (2, 1, 2): ['B', 'AC', 'AC'],
#         (1, 4, 3): ['B', 'A', 'BC', 'BC', 'BC'],
#         (1, 3, 3): ['A', 'BC', 'BC', 'BC'],
#         (1, 2, 2): ['A', 'BC', 'BC'],
#         (1, 2, 3): ['C', 'A', 'BC', 'BC'],
#         (1, 1, 1): ['A', 'BC'],
#         (4, 3, 1): ['A', 'C', 'AB', 'AB', 'AB'],
#         (3, 4, 1): ['B', 'C', 'AB', 'AB', 'AB'],
#         (1, 3, 2): ['B', 'A', 'BC', 'BC'],
#         (4, 4, 1): ['C', 'AB', 'AB', 'AB', 'AB'],
#         (4, 2, 2): ['AA', 'AA', 'BC', 'BC'],
#         # (1, 4, 4): [''],
#         # (2, 1, 3): [''],
#         # (4, 1, 4): [''],
#         # (2, 1, 1): [''],
#         # (2, 2, 4): [''],
#         # (2, 2, 2): [''],
#         # (3, 3, 1): [''],
#         # (2, 3, 4): [''],
#         # (3, 2, 4): [''],
#         # (3, 1, 4): [''],
#         # (2, 2, 1): [''],
#         # (3, 3, 2): [''],
#         # (4, 1, 3): [''],
#         # (1, 3, 4): [''],
#         # (2, 4, 2): [''],
#     }
#
#     for t, answer in cases.items():
#         print('Running test {}, expected answer: {}'.format(t, answer))
#         res = list(solve(t))
#         assert res == answer, 'Given {}, expected {}, received {}'.format(t, answer, res)
#
#     print('All tests passed')
#

def main():
    # run_all_tests()
    n = int(input())
    for i in range(1, n + 1):
        j, p, s, k = [int(x) for x in input().split()]
        ans = solve(j, p, s, k)
        print('Case #{}: {}'.format(i, len(ans)))
        for jj, pp, ss in ans:
            print(jj, pp, ss)


if __name__ == "__main__":
    main()
