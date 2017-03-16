#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# $File: trans.py
# $Date: Sat Apr 14 08:24:58 2012 +0800
# $Author: jiakai <jia.kai66@gmail.com>

def mktrmap():
    n  = int(raw_input())

    trmap = dict()

    for i in range(n):
        a = raw_input()
        b = raw_input()
        assert len(a) == len(b)
        for j in range(len(a)):
            ch1 = a[j]
            ch2 = b[j]
            if ch1 in trmap:
                assert trmap[ch1] == ch2
            else:
                trmap[ch1] = ch2


    not_key = None
    not_val = None

    trmap_key = set(trmap.iterkeys())
    trmap_val = set(trmap.itervalues())

    assert len(trmap_key) == len(trmap)
    assert len(trmap_val) == len(trmap)

    for i in range(ord('a'), ord('z') + 1):
        ch = chr(i)
        if ch not in trmap_key:
            assert not_key is None
            not_key = ch
        if ch not in trmap_val:
            assert not_val is None
            not_val = ch

    if not_key:
        trmap[not_key] = not_val

    return trmap


def work(trmap):
    import sys

    n = int(raw_input())

    for i in range(n):
        print 'Case #' + str(i + 1) + ':',
        s = raw_input()

        for j in s:
            sys.stdout.write(trmap[j])

        sys.stdout.write('\n')


if __name__ == '__main__':
    work(mktrmap())
