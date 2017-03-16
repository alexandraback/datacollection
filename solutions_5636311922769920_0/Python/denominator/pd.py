#!/usr/bin/env python2.7

import sys

def slv_line(cs_n, ln):
    cs_n += 1
    K, C, S = map(int, ln.split(' '))

    res = ''
    for i in range(K):
        res += str(i+1) + ' '
    res = res.strip()


    print 'Case #%s: %s' %(str(cs_n), str(res))


if __name__ == '__main__':
    T = sys.stdin.readline().strip('\n')

    for cs_n, line in enumerate(sys.stdin):
        slv_line(cs_n, line.strip('\n'))
