#!/usr/bin/env python3

import sys
from collections import *

def nine(string):
    return string.replace('?', '9')

def zero(string):
    return string.replace('?', '0')


def check(pa, ra, pb, rb):
    global result
    a = int(pa + nine(ra))
    b = int(pb + zero(rb))
    result = min(result, (abs(a-b), a, b))

    a = int(pa + zero(ra))
    b = int(pb + nine(rb))
    result = min(result, (abs(a-b), a, b))



TC = int(input())
for tc in range(1, TC+1):
    pa, pb = '', ''
    ra, rb = input().split(' ')
    result = (10**10, 42, 42)

    assert len(ra) == len(rb)
    x = len(ra)

    while len(ra) > 0:
        ma, mb = ra[0], rb[0]
        ra = ra[1:]
        rb = rb[1:]

        if ma != '?' and mb != '?':
            pa += ma
            pb += mb

            if ma != mb:
                check(pa, ra, pb, rb)
                break

        elif ma == '?' and mb == '?':
            check(pa + '0', ra, pb + '1', rb)
            check(pa + '1', ra, pb + '0', rb)

            pa += '0'
            pb += '0'

        elif ma == '?':
            if mb != '0': check(pa + chr(ord(mb) - 1), ra, pb + mb, rb)
            if mb != '9': check(pa + chr(ord(mb) + 1), ra, pb + mb, rb)

            pa += mb
            pb += mb

        else:
            assert mb == '?'

            if ma != '0': check(pa + ma, ra, pb + chr(ord(ma) - 1), rb)
            if ma != '9': check(pa + ma, ra, pb + chr(ord(ma) + 1), rb)

            pa += ma
            pb += ma


    if len(ra) == 0 and pa == pb:
        result = (0, int(pa), int(pb))

    print('Case #{}: {:0>{}} {:0>{}}'.format(tc, result[1], x, result[2], x))
