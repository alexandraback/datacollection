# coding: utf-8
# python 3

import sys

def solve(N, AB):
    assert(N == len(AB))
    stars = 0
    result = 0
    completed = [0] * N

    def solve_2_greedy():
        nonlocal stars
        nonlocal result
        gupdated = False
        while True:
            updated = False
            for index, ab in enumerate(AB):
                a, b = ab
                if completed[index] != 2 and b <= stars:
                    result += 1
                    stars += 2 - completed[index]
                    completed[index] = 2
                    updated = True
                    gupdated = True
            if not updated:
                break
        return gupdated

    def solve_1_once():
        nonlocal stars
        nonlocal result
        for index, ab in sorted(enumerate(AB), key=lambda x: x[1][1], reverse=True):
            a, b = ab
            if completed[index] == 0 and a <= stars:
                result += 1
                stars += 1
                completed[index] = 1
                return True
        return False

    while True:
        solve_2_greedy()
        if not solve_1_once():
            if stars == N * 2:
                return result
            return None

with open(sys.argv[1]) as f:
    lines = list(filter(None, f.read().split('\n')))
    T = int(lines.pop(0))
    for i in range(T):
        levels = N = int(lines.pop(0))
        AB = []
        for level in range(levels):
            a, b = map(int, lines.pop(0).split())
            AB.append((a, b))
        result = solve(N, AB)
        print('Case #{0}: {1}'.format(i + 1, result if result else 'Too Bad'))
