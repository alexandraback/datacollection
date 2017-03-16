#!env python2

import sys


INFINITY = float('+inf')


def play_game(a_mote_size, motes):
    while len(motes) > 0 and a_mote_size > motes[-1]:
        a_mote_size += motes[-1]
        motes.pop()

    if len(motes) == 0:
        return 0;

    removes = len(motes)

    if a_mote_size > 1:
        adds = 1 + play_game(a_mote_size, motes + [a_mote_size - 1])
    else:
        adds = INFINITY

    return min(adds, removes)


def read_ints(line):
    return map(int, line.strip().split(' '))


def read_input():
    count = int(sys.stdin.readline().strip())

    for _ in range(count):
        a_mote_size, _ = read_ints(sys.stdin.readline())
        motes = sorted(read_ints(sys.stdin.readline()))[::-1]

        yield a_mote_size, motes


case = 1
for a_mote_size, motes in read_input():
    result = play_game(a_mote_size, motes)
    print "Case #%d: %s" % (case, result)
    case += 1
