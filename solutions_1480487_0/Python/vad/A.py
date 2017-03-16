from __future__ import division
import sys
from datetime import datetime

f = None
START = datetime.now()

def read_int():
    return int(f.readline())

def read_ints():
    return map(int, f.readline().split())

def read_word():
    return f.readline().strip()

def char_range(start, end):
    return [chr(i) for i in range(ord(start), ord(end) + 1)]

############################################################################

def solve(s):
    fixed_X = 0
    alive = 0
    X = sum(s)
    N = len(s)
    saved = 2.*X/N
    out = [None]*N
    for i, si in enumerate(s):
        needs = saved - float(si)
        if needs <= 0:
            out[i] = 0.
        else:
            fixed_X += si
            alive += 1

    saved = (X+fixed_X)/alive
    for i, si in enumerate(s):
        needs = saved - float(si)
        if out[i] is not None:
            continue
        try:
            out[i] = 100.*needs/X
        except ZeroDivisionError:
            out[i] = 100.
    return out

def main():
    global f

    with open(sys.argv[1]) as f:
        t = read_int()

        for index in range(t):
            print >>sys.stderr, 'Working on case #', index + 1, datetime.now() - START
            ints = read_ints()
            n, s = ints[0], ints[1:]

            result = ' '.join(map(str, solve(s)))

            print 'Case #{0}: {1}'.format(index + 1, result)


if __name__ == '__main__':
    main()
