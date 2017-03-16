#!/usr/bin/python3

from fractions import gcd


def next_line_to_ints(lines, delimiter=' '):
    return map(int, next(lines).split(delimiter))

f_in = open('a.in')
f_out = open('a.out', 'w')

lines = (i for i in f_in.read().splitlines())
t = int(next(lines))

q_options = list(map(lambda x: 2**x, range(0, 41)))

for case in range(1, t+1):
    p, q = next_line_to_ints(lines, '/')

    div = gcd(p, q)
    p /= div
    q /= div

    if q not in q_options:
        answer = 'impossible'
    else:
        while p > 1:
            p -= 1
            div = gcd(p, q)
            p /= div
            q /= div
        answer = q_options.index(q)

    f_out.write('Case #{!s}: {!s}\n'.format(case, answer))
