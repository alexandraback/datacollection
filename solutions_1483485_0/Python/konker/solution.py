#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Author: Konrad Markus <konker@gmail.com>
#

import sys

SAMPLE_IN = [
    'ejp mysljylc kd kxveddknmc re jsicpdrysi',
    'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd',
    'de kr kd eoya kw aej tysr re ujdr lkgc jv'
]
SAMPLE_OUT = [
    'our language is impossible to understand',
    'there are twenty six factorial possibilities',
    'so it is okay if you want to just give up'
]

MAPPING = None

def main():
    prepare()

    T = int(sys.stdin.readline().rstrip())

    t = 1
    while (t <= T):
        s = sys.stdin.readline().rstrip()

        solve(t, s)
        t = t + 1

def prepare():
    from string import lowercase
    global MAPPING

    # analyse SAMPLE_IN and SAMPLE_OUT
    # and generate mapping
    ct = ' '.join(SAMPLE_IN)
    pt = ' '.join(SAMPLE_OUT)

    MAPPING = dict(set(zip(ct, pt)))
    
    # q and z are missing. from description z -> q
    MAPPING['z'] = 'q'

    # find the missing value
    diff = set(lowercase) - set(MAPPING.values())
    assert len(diff) == 1

    MAPPING['q'] = diff.pop()


def solve(t, s):
    sys.stdout.write("Case #")
    sys.stdout.write(str(t))
    sys.stdout.write(": ")

    for c in s:
        sys.stdout.write(MAPPING[c])

    sys.stdout.write("\n")

if __name__ == '__main__':
    main()

