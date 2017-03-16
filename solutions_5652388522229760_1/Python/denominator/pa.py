#!/usr/bin/env python2.7

import sys

def slv_line(cs_n, ln):
    cs_n += 1
    n = int(ln)

    digit = {}
    res = ''

    i = 1
    if n == 0:
        res = 'INSOMNIA'
    else:
        while True:
            str_n = str(n * i)
            for dig in str_n:
                digit[dig] = ''
            i += 1
            if len(digit) == 10:
                res = str_n
                break

    print 'Case #%d: %s' %(cs_n, res)


if __name__ == '__main__':
    T = sys.stdin.readline().strip('\n')

    for cs_n, line in enumerate(sys.stdin):
        slv_line(cs_n, line.strip('\n'))
