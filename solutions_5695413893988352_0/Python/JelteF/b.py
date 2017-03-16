#!/usr/bin/python3

from itertools import count  # noqa


def next_line_to_flts(lines):
    return map(float, next(lines).split(' '))

f_in = open('b.in')
f_out = open('b.out', 'w')

lines = (i for i in f_in.read().splitlines())
t = int(next(lines))

for case in range(1, t+1):
    s = next(lines)
    left, right = s.split()
    largest = None
    switch = 999999999999999999
    last_question_mark = 9999999999999999999
    diff = None
    for i, (l, r) in enumerate(zip(left, right)):
        try:
            l = int(l)
            r = int(r)
        except:
            last_question_mark = i
            continue
        if l > r:
            largest = 'l'
            switch = i
            diff = l - r
            break
        if l < r:
            largest = 'r'
            switch = i
            diff = r - l
            break

    l_list = []
    r_list = []

    if largest:
        if largest == 'r':
            left, right = right, left

        for i, (l, r) in enumerate(zip(left, right)):
            try:
                l = int(l)
            except:
                pass
            try:
                r = int(r)
            except:
                pass

            if i < switch:
                if r == '?' and l == '?':
                    r_list.append(0)
                    l_list.append(0)
                elif r == '?':
                    if last_question_mark == i and diff > 5:
                        r_list.append(l + 1)
                    else:
                        r_list.append(l)
                    l_list.append(l)
                elif l == '?':
                    r_list.append(r)
                    if last_question_mark == i and diff > 5:
                        l_list.append(r - 1)
                    else:
                        l_list.append(r)
                else:
                    r_list.append(r)
                    l_list.append(l)
            else:
                if r == '?' and l == '?':
                    r_list.append(9)
                    l_list.append(0)
                elif r == '?':
                    r_list.append(9)
                    l_list.append(l)
                elif l == '?':
                    r_list.append(r)
                    l_list.append(0)
                else:
                    r_list.append(r)
                    l_list.append(l)

        if largest == 'r':
            l_list, r_list = r_list, l_list

    if largest is None:
        for i, (l, r) in enumerate(zip(left, right)):
            try:
                l = int(l)
            except:
                pass
            try:
                r = int(r)
            except:
                pass

            if r == '?' and l == '?':
                r_list.append(0)
                l_list.append(0)
            elif r == '?':
                r_list.append(l)
                l_list.append(l)
            elif l == '?':
                r_list.append(r)
                l_list.append(r)
            else:
                r_list.append(r)
                l_list.append(l)

    print(l_list, r_list)
    print(last_question_mark)
    print(diff)

    l = ''.join(map(str, l_list))
    r = ''.join(map(str, r_list))
    f_out.write('Case #{}: {} {}\n'.format(case, l, r))
