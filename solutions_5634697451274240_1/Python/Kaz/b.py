#!/usr/local/bin/python3

import fileinput

for cs, case in enumerate(list(fileinput.input())[1:]):
    case = case.rstrip() + '+'

    result = 0
    prev = case[0]
    for x in case[1:]:
        if x != prev:
            result += 1
        prev = x

    print('Case #{}: {}'.format(cs + 1, result))
