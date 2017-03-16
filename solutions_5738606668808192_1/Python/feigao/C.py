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

@io_wrapper
def coin_jam_large(line='32 500'):
    N, J = map(int, line.split())
    results = []
    fs = list(range(3, 12))
    for num in range(1 << (N // 2 - 1), (1 << (N // 2 - 1)) + J):
        s1 = '{:b}'.format(num)
        results.append([s1 + s1[::-1]] + fs)
    assert len(results) == J
    return ''.join(('\n' + ' '.join(map(str, r))) for r in results)


def verify(s, *fs):
    return len(fs) == 9 and all(((int(s, b) % int(f)) == 0) for b, f in enumerate(fs, 2))


if __name__ == '__main__':
    # counting_sheep('A-sample.txt')
    # revenge_of_the_pancakes()
    coin_jam_large('C-large-attempt0.in.txt', 'C-large-attempt0.out.txt')
    pass
