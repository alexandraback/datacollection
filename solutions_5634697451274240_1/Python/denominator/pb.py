#!/usr/bin/env python2.7

import sys

def slv_line(cs_n, ln):
    cs_n += 1
    pl = ln + '+'

    res = 0

    for i in range(len(ln)):
        if pl[i] != pl[i+1]:
            res += 1

    print 'Case #%s: %s' %(str(cs_n), str(res))


if __name__ == '__main__':
    T = sys.stdin.readline().strip('\n')

    for cs_n, line in enumerate(sys.stdin):
        slv_line(cs_n, line.strip('\n'))
