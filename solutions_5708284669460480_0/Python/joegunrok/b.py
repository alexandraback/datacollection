#!/usr/bin/python

import sys
VERBOSE = True

sin = sys.stdin
line = lambda : sin.readline().strip()

class case(object):
    def __init__(self, number):
        self.number = number
        self.r = ""

    def __enter__(self):
        return self

    def __exit__(self, *arg):
        print "Case #%s: %s" % (self.number, self.r)


def parse_result(out):
    return out.readline().strip()


def main():
    TEST_CASES = int(line())
    for CASE_NUMBER in range(1, TEST_CASES+1):
        with case(CASE_NUMBER) as CASE:
            _run(CASE, **parse())


def parse():
    K, L, S = map(int, sin.readline().strip().split(" "))
    ALPHA = sin.readline().strip()
    STRING = sin.readline().strip()
    return dict(K=K, L=L, S=S, ALPHA=ALPHA, STRING=STRING)

def _run(CASE, K=None, L=None, S=None, ALPHA=None, STRING=None):
    CASE.r = 0
    if len(STRING) > S:
        return

    lexicon = []
    for c in ALPHA:
        lexicon.append(c)
    for i in range(S-1):
        for w in lexicon[:]:
            for c in ALPHA:
                nw = w + c
                lexicon.append(nw)

    v = 0
    tot = 0
    most = 0
    for w in lexicon:
        if len(w) == S:
            v += 1
            c = 0
            m = 0
            while STRING in w[c:]:
                c += w[c:].index(STRING) + 1
                m += 1
            most = max(most, m)
            tot += m
    CASE.r = most - float(tot)/float(v)


if __name__ == "__main__":
    main()
