# -*- coding: utf-8

import sys
sys.setrecursionlimit(10 ** 6 + 1)

def cnt(n):
    lst = range(n+1)
    for i in xrange(1, n+1):
        revi = int(''.join(reversed(str(i))))
        lst[i] = min(lst[i], lst[i-1]+1, lst[revi]+1 if str(i)[-1] != '0' and revi < i else i)
    return lst[n]

def main():
    t = int(raw_input())
    for i in xrange(1, t+1):
        print 'Case #%d: %d' % (i, cnt(int(raw_input())))

if __name__ == '__main__':
    main()
