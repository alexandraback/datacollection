#!/usr/bin/env python3
# -*- coding: utf-8 -*-


import os
import sys
from functools import wraps, lru_cache


def io_wrapper(func):
    @wraps(func)
    def _func(in_file=None, out_file=None, lines_per_case=1):
        in_buffers = []
        if in_file is None:
            while True:
                try:
                    s = input()
                    if s.strip():
                        in_buffers.append(s.strip())
                except:
                    break
        else:
            with open(in_file, 'r') as f:
                in_buffers.extend([line.strip() for line in f.read().strip().splitlines()])
        total_case_nums = int(in_buffers[0])
        in_buffers = in_buffers[1:]
        # print(in_buffers)
        assert len(in_buffers) == total_case_nums * lines_per_case

        out_buffers = []
        for case_id in range(1, total_case_nums + 1):
            case_result_str = func('\n'.join(in_buffers[(case_id - 1) * lines_per_case: case_id * lines_per_case]))
            out_buffers.append('Case #{}: {}'.format(case_id, case_result_str))

        if out_file is not None and os.path.exists(out_file):
            print('Out file {} already exists!'.format(out_file), file=sys.stderr)
            out_buffers = None
        if out_file is None:
            print('\n'.join(out_buffers))
        else:
            with open(out_file, 'w') as f:
                f.write('\n'.join(out_buffers))

    return _func


@io_wrapper
@lru_cache(maxsize=None)
def solution(line_str):
    return "Answer Str"


@io_wrapper
def a(lines):
    n, *parties = map(int, lines.split())
    # print(n, parties)
    resutls = []
    total = sum(parties)
    import string
    names = string.ascii_uppercase[:n]
    numbers = dict(zip(names, parties))

    while total > 0:
        m = max(numbers, key=lambda c: numbers[c])
        resutls.append(m)
        total -= 1

        v = numbers[m]
        if v == 1:
            del numbers[m]
        else:
            numbers[m] = v - 1

    if len(resutls) % 2 == 1:
        resutls.insert(0, '')
    return ' '.join(a + b for a, b in zip(resutls[::2], resutls[1::2]))


@io_wrapper
def b(lines):
    # print(lines)
    b, m = map(int, lines.split())
    if m > 2 ** (b - 2):
        return 'IMPOSSIBLE'
    resp = 'POSSIBLE'

    if m == 2 ** (b - 2):
        matrix = [[1 if r < c else 0 for c in range(b)] for r in range(b)]
    else:
        matrix = [[1 if r < c < b - 1 else 0 for c in range(b)] for r in range(b)]
        for r in range(b):
            if m & (2 ** r):
                matrix[r + 1][b - 1] = 1

    return '\n'.join([resp] + [''.join(map(str, row)) for row in matrix])


@io_wrapper
def c(lines):
    J, P, S, K = map(int, lines.split())
    Js = list(range(1, J + 1))
    Ps = list(range(1, P + 1))
    Ss = list(range(1, S + 1))
    JS_pairs = [(j, s) for j in Js for s in Ss]

    from collections import defaultdict
    JP_count = defaultdict(int)
    JS_count = defaultdict(int)
    PS_count = defaultdict(int)

    results = []

    def check_count(j, p, s):
        return JP_count[(j, p)], PS_count[(p, s)], JS_count[(j, s)]

    def update_count(j, p, s):
        JP_count[(j, p)] += 1
        PS_count[(p, s)] += 1
        JS_count[(j, s)] += 1

    while True:
        added = False
        for p in Ps:
            j, s = min(JS_pairs, key=lambda x: JS_count[x])
            if (j, p, s) not in results and max(check_count(j, p, s)) < K:
                update_count(j, p, s)
                results.append((j, p, s))
                added = True
        if not added:
            break

    return '\n'.join([str(len(results))] +
                     [' '.join(map(str, row)) for row in results])


if __name__ == '__main__':
    # solution()
    # a('A-sample.txt', lines_per_case=2)
    # a('A-small-attempt0.in', lines_per_case=2)
    # a('A-large.in.txt', 'A-large.out.txt', lines_per_case=2)

    # b('B-sample.txt')
    # b('B-small-attempt0.in.txt', 'B-small-attempt0.out.txt')
    # b('B-large.in', 'B-large.out.txt')

    # c('C-sample.txt')
    c('C-small-attempt0.in.txt', 'C-small-attempt0.out.txt')
    # c('C-large.in', 'C-large.out.txt')
    pass
