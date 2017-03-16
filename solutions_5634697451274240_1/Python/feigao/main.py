#!/usr/bin/env python3
# -*- coding: utf-8 -*-


import os
import sys
from functools import wraps, lru_cache


def io_wrapper(func):
    @wraps(func)
    def _func(in_file=None, out_file=None):
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
        assert len(in_buffers) == int(in_buffers[0]) + 1

        out_buffers = []
        for case_id, line in enumerate(in_buffers[1:], 1):
            out_buffers.append('Case #{}: {}'.format(case_id, func(line)))

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
def counting_sheep(N):
    N = int(N)
    if N == 0:
        return 'INSOMNIA'
    steps = 0
    digits = set()
    while len(digits) < 10:
        steps += 1
        digits.update(list(set(str(N * steps))))
        # print(N, steps, digits)
    return str(steps * N)


@io_wrapper
@lru_cache(maxsize=None)
def revenge_of_the_pancakes(line: str):
    line = line.rstrip('+')
    if not line: return 0
    signs = [line[0]]
    for s in line[1:]:
        if s != signs[-1]:
            signs.append(s)
    return str(len(signs))


@io_wrapper
def coin_jam(line='32 500'):
    N, J = map(int, line.split())
    results = []
    fs = list(range(3, 12))
    for num in range(1 << (N // 2 - 1), (1 << (N // 2 - 1)) + J):
        s1 = '{:b}'.format(num)
        results.append([s1 + s1[::-1]] + fs)
    assert len(results) == J
    return ''.join(('\n' + ' '.join(map(str, r))) for r in results)


def verify(line):
    s, *fs = line.split()
    return len(fs) == 9 and all(((int(s, b) % int(f)) == 0) for b, f in enumerate(fs, 2))


def test_c():
    # print(open('C-small-attempt0.out.txt').read().splitlines()[1:])
    print(all(map(verify, open('C-small-attempt0.out.txt').read().splitlines()[1:])))

    for line in open('C-small-attempt0.out.txt').read().splitlines()[1:]:
        if verify(line) is False:
            print(line)


@io_wrapper
def fractiles(line):
    K, C, S = map(int, line.split())
    if C * S < K:
        return 'IMPOSSIBLE'
    from math import ceil
    S = ceil(K / C)
    digits = list(range(K))
    results = []
    for i in range(S):
        num = sum(digits[j % K] * (K ** (C * i + C - 1 - j))
                  for j in range(C * i, C * i + C))
        results.append(num + 1)
    return ' '.join(map(str, results))


if __name__ == '__main__':
    # counting_sheep('A-sample.txt')
    revenge_of_the_pancakes('B-large.in.txt', 'B-large.out.txt')
    # coin_jam('C-small-attempt0.in.txt', 'C-small-attempt0.out.txt')
    # fractiles('D-large.in.txt', 'D-large.out.txt')
    pass
