from __future__ import print_function
from __future__ import division
import sys
#from itertools import izip, ifilter, imap
#from collections import defaultdict

import gcj_util
from gcj_util import (
    dprint,
    read_ints,
    read_floats,
    read_int,
)


nletters = 26
letters = map(chr, range(ord('a'), ord('z') + 1))
mod = 1000000007

class Letter(object):

    def __init__(self, c):
        self.c = c
        self.trains_with_only_c = 0
        self.ntrains = 0
        self.is_frozen = False
        self.train_startswith = None
        self.train_endswith = None
        self.next = None
        self.prev = None


def has_loop(info):
    if not info.next:
        return False

    c = info.c
    step = 0
    info = info.next
    while info.next and step <= nletters:
        if info.c == c:
            return True
        info = info.next
        step += 1
    return False


def solve(_ntrains, trains):

    letters_info = dict((c, Letter(c)) for c in letters)

    for i, t in enumerate(trains):
        contains = set(t)

        if len(contains) == 1:
            info = letters_info[t[0]]
            if info.is_frozen:
                return 0

            info.trains_with_only_c += 1
        else:
            assert len(t) > 1
            startswith = t[0]
            endswith = t[-1]
            frozen = contains.difference([startswith, endswith])
            for c in frozen:
                info = letters_info[c]
                if info.ntrains:
                    return 0

                info.ntrains += 1
                info.is_frozen = True

            # "cxc" - cannot be, we ruled out "ccc" in prev. branch
            if startswith == endswith:
                return 0

            info = letters_info[startswith]
            if info.train_startswith:
                return 0
            info.train_startswith = t
            info.ntrains += 1

            info = letters_info[endswith]
            if info.train_endswith:
                return 0
            info.train_endswith = t
            info.ntrains += 1

    for c, info in letters_info.iteritems():
        if info.ntrains == 0:
            continue

        #if info.prev is not None:
        #    continue

        if info.train_endswith is not None:
            prev_letter = info.train_endswith[0]
            assert prev_letter != info.c, (info.train_startswith, info.c)
            prev_letter_info = letters_info[prev_letter]

            if info.prev is not None and info.prev != prev_letter_info:
                return 0

            info.prev = prev_letter_info

            if prev_letter_info.next is not None and prev_letter_info.next != info:
                return 0
            prev_letter_info.next = info

        if info.train_startswith is not None:
            next_letter = info.train_startswith[-1]
            assert next_letter != info.c
            next_letter_info = letters_info[next_letter]

            if info.next is not None and info.next != next_letter_info:
                return 0

            if next_letter_info.prev is not None and next_letter_info.prev != info:
                return 0

            info.next = next_letter_info
            next_letter_info.prev = info


    contrib = 1

    nconnected = 0

    for c, info in letters_info.iteritems():
        if has_loop(info):
            return 0

        if info.prev is not None:
            continue
        if info.prev is None and info.next is None:
            if info.trains_with_only_c:
                contrib = (contrib * factorial(info.trains_with_only_c)) % mod
                nconnected += 1
            else:
                assert info.ntrains == 0 or info.is_frozen
            continue

        nconnected += 1
        assert info.next is not None

        while info:
            if info.trains_with_only_c:
                contrib = (contrib * factorial(info.trains_with_only_c)) % mod
            info = info.next

    return (factorial(nconnected) * contrib) % mod


def factorial(n):
    ret = 1
    for i in range(1, n + 1):
        ret *= i % mod
    return ret


def read_case(fp):
    n = read_int(fp)
    trains = fp.readline().strip().split(' ')
    return n, trains


def write_result(fp, casenum, result):
    fp.write('Case #%d: %s\n' % (casenum, result))
    fp.flush()


def read_cases(fp):
    T = read_int(fp)
    for i in range(T):
        yield read_case(fp)


if __name__ == '__main__':
    if len(sys.argv) > 1:
        gcj_util.DEBUG = True

    in_fp = sys.stdin
    out_fp = sys.stdout
    for casenum, case in enumerate(read_cases(in_fp)):
        result = solve(*case)
        write_result(out_fp, casenum + 1, result)
