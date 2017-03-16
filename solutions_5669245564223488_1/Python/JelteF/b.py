#!/usr/bin/python3

from string import ascii_lowercase
from math import factorial


def next_line_to_ints(lines, delimiter=' '):
    return map(int, next(lines).split(delimiter))


def is_correct_car(c, l, cars_wo_others, multiple):
    if (multiple or cars_wo_others) and c[0] != l and c[-1] != l:
        return False
    if c[c.find(l):c.rfind(l)].strip(l):
        return False
    return True

f_in = open('b.in')
f_out = open('b.out', 'w')

lines = (i for i in f_in.read().splitlines())
t = int(next(lines))


for case in range(1, t+1):
    n = int(next(lines))
    cars = next(lines).split(' ')
    combinations = 1

    for l in ascii_lowercase:
        cars_with_l = [c for c in cars if l in c]
        cars_wo_l = [c for c in cars if l not in c]
        if not len(cars_with_l):
            continue

        cars_with_others = [c for c in cars_with_l if c.strip(l)]
        cars_wo_others = [c for c in cars_with_l if not c.strip(l)]
        new_car = ''

        if len(cars_with_others) > 2:
            combinations = 0
            break
        elif len(cars_with_others) == 2:
            first, last = cars_with_others
            if not is_correct_car(first, l, cars_wo_others, True) or \
                    not is_correct_car(last, l, cars_wo_others, True):
                combinations = 0
                break
            if (first[0] != l and last[0] != l) or \
                    (first[-1] != l and last[-1] != l):
                combinations = 0
                break

            if first[0] != l:
                new_car = first + ''.join(cars_wo_others) + last
            else:
                new_car = last + ''.join(cars_wo_others) + first

        elif len(cars_with_others) == 1:
            strange_car = cars_with_others[0]
            if not is_correct_car(strange_car, l, cars_wo_others, False):
                combinations = 0
                break

            if strange_car[0] != l:
                new_car = strange_car + ''.join(cars_wo_others)
            else:
                new_car = ''.join(cars_wo_others) + strange_car
        else:
            new_car = ''.join(cars_wo_others)

        cars_wo_l.append(new_car)
        cars = cars_wo_l

        combinations *= factorial(len(cars_wo_others))

    combinations *= factorial(len(cars))

    f_out.write('Case #{!s}: {!s}\n'.format(case, combinations % 1000000007))
