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
def coin_jam(line):
    N, J = map(int, line.split())
    results = []
    num_str = '{:b}'.format((1 << (N - 1)) - 1)
    while len(results) < J:
        num_str = '{:b}'.format(int(num_str, 2) + 2)
        prime = False
        fs = []
        for base in range(2, 11):
            num = int(num_str, base)
            div = factor(num)
            if div == -1:
                prime = True
                break
            else:
                fs.append(div)
        if not prime:
            results.append([num_str] + fs)
    return ''.join(('\n' + ' '.join(map(str, r))) for r in results)


@lru_cache(maxsize=None)
def factor(num):
    """return a non-trivial factor of num, otherwise -1"""
    f = 2
    while f * f <= num:
        if num % f == 0:
            return f
        else:
            f += 1
    return -1


def test_factor():
    for n in range(2, 11):
        print(n, factor(n))


# test_factor()


if __name__ == '__main__':
    # counting_sheep('A-sample.txt')
    # revenge_of_the_pancakes()
    coin_jam('C-small-attempt0.in.txt', 'C-small-attempt0.out.txt')
    pass
