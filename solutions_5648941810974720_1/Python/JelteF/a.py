#!/usr/bin/python3

from collections import Counter


def next_line_to_ints(lines):
    return map(int, next(lines).split(' '))

f_in = open('a.in')
f_out = open('a.out', 'w')

lines = (i for i in f_in.read().splitlines())
t = int(next(lines))

for case in range(1, t+1):
    s = next(lines).lower()
    nums = []
    chars = Counter(s)
    while chars and list(chars.elements()):
        found = None
        if chars['x']:
            found = 6, 'six'
        elif chars['z']:
            found = 0, 'zero'
        elif chars['g']:
            found = 8, 'eight'
        elif chars['w']:
            found = 2, 'two'
        elif chars['t']:
            found = 3, 'three'
        elif chars['u']:
            found = 4, 'four'
        elif chars['f']:
            found = 5, 'five'
        elif chars['v']:
            found = 7, 'seven'
        elif chars['i']:
            found = 9, 'nine'
        elif chars['o']:
            found = 1, 'one'

        print(chars, found)
        nums.append(found[0])

        for c in found[1]:
            chars[c] -= 1

    phone = ''.join(map(str, sorted(nums)))
    f_out.write('Case #{}: {}\n'.format(case, phone))
